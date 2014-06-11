$NetBSD: patch-etc_afpd_quota.c,v 1.1 2014/06/11 11:03:57 hauke Exp $

--- etc/afpd/quota.c.orig	2013-04-09 12:56:18.000000000 +0000
+++ etc/afpd/quota.c
@@ -36,10 +36,13 @@
 
 static int
 getfreespace(const AFPObj *obj, struct vol *vol, VolSpace *bfree, VolSpace *btotal,
-	     uid_t uid, const char *classq)
+	     id_t id, int idtype)
 {
-	int retq;
-	struct ufs_quota_entry ufsq[QUOTA_NLIMITS];
+	uid_t prevuid;
+	const char *msg;
+	struct quotahandle *qh;
+	struct quotakey qk;
+	struct quotaval qv;
 	time_t now;
 
 	if (time(&now) == -1) {
@@ -48,64 +51,102 @@ getfreespace(const AFPObj *obj, struct v
 		return -1;
 	}
 
+	prevuid = geteuid();
+	if (prevuid == -1) {
+		LOG(log_info, logtype_afpd, "geteuid(): %s",
+		    strerror(errno));
+		return -1;
+	}
+
     become_root();
 
-	if ((retq = getfsquota(obj, vol, ufsq, uid, classq)) < 0) {
-		LOG(log_info, logtype_afpd, "getfsquota(%s, %s): %s",
-		    vol->v_path, classq, strerror(errno));
-	}
-
-    unbecome_root();
-
-	if (retq < 1)
-		return retq;
-
-	switch(QL_STATUS(quota_check_limit(ufsq[QUOTA_LIMIT_BLOCK].ufsqe_cur, 1,
-	    ufsq[QUOTA_LIMIT_BLOCK].ufsqe_softlimit,
-	    ufsq[QUOTA_LIMIT_BLOCK].ufsqe_hardlimit,
-	    ufsq[QUOTA_LIMIT_BLOCK].ufsqe_time, now))) {
-	case QL_S_DENY_HARD:
-	case QL_S_DENY_GRACE:
+	/*
+	 * In a tidier world we might keep the quotahandle open for longer...
+	 */
+	qh = quota_open(vol->v_path);
+	if (qh == NULL) {
+		if (errno == EOPNOTSUPP || errno == ENXIO) {
+			/* no quotas on this volume */
+			seteuid( prevuid );
+			return 0;
+		}
+	   
+		LOG(log_info, logtype_afpd, "quota_open(%s): %s", vol->v_path,
+		    strerror(errno));
+		seteuid( prevuid );
+		return -1;
+	}
+	qk.qk_idtype = idtype;
+	qk.qk_id = id;
+	qk.qk_objtype = QUOTA_OBJTYPE_BLOCKS;
+	if (quota_get(qh, &qk, &qv) < 0) {
+		if (errno == ENOENT) {
+			/* no quotas for this id */
+			quota_close(qh);
+			seteuid( prevuid );
+			return 0;
+		}
+		msg = strerror(errno);
+		LOG(log_info, logtype_afpd, "quota_get(%s, %s): %s",
+		    vol->v_path, quota_idtype_getname(qh, idtype), msg);
+		quota_close(qh);
+		seteuid( prevuid );
+		return -1;
+	}
+
+	quota_close(qh);
+
+	 seteuid( prevuid );
+
+	if (qv.qv_usage >= qv.qv_hardlimit ||
+            (qv.qv_usage >= qv.qv_softlimit && now > qv.qv_expiretime)) {
+
 		*bfree = 0;
-		*btotal = dbtob(ufsq[QUOTA_LIMIT_BLOCK].ufsqe_cur);
-		break;
-	default:
-		*bfree = dbtob(ufsq[QUOTA_LIMIT_BLOCK].ufsqe_hardlimit -
-		    ufsq[QUOTA_LIMIT_BLOCK].ufsqe_cur);
-		*btotal = dbtob(ufsq[QUOTA_LIMIT_BLOCK].ufsqe_hardlimit);
-		break;
+		*btotal = dbtob(qv.qv_usage);
+	}
+	else {
+		*bfree = dbtob(qv.qv_hardlimit - qv.qv_usage);
+		*btotal = dbtob(qv.qv_hardlimit);
+	}
+
 	}
 	return 1;
 }
 
 int uquota_getvolspace(const AFPObj *obj, struct vol *vol, VolSpace *bfree, VolSpace *btotal, const u_int32_t bsize)
 {
-	int uretq, gretq;
+	int uret, gret;
 	VolSpace ubfree, ubtotal;
 	VolSpace gbfree, gbtotal;
+	uret = getfreespace(vol, &ubfree, &ubtotal,
+	    uuid, QUOTA_IDTYPE_USER);
+	if (uret == 1) {
+		LOG(log_info, logtype_afpd, "quota_get(%s, user): %d %d",
+		    vol->v_path, (int)ubfree, (int)ubtotal);
+	}
 
-	uretq = getfreespace(obj, vol, &ubfree, &ubtotal,
-			     uuid, QUOTADICT_CLASS_USER);
-	LOG(log_info, logtype_afpd, "getfsquota(%s): %d %d",
-	    vol->v_path, (int)ubfree, (int)ubtotal);
 	if (obj->ngroups >= 1) {
-		gretq = getfreespace(vol, &ubfree, &ubtotal,
-		    obj->groups[0], QUOTADICT_CLASS_GROUP);
+		gret = getfreespace(vol, &gbfree, &gbtotal,
+		    groups[0], QUOTA_IDTYPE_GROUP);
+		if (gret == 1) {
+			LOG(log_info, logtype_afpd, "quota_get(%s, group): %d %d",
+			    vol->v_path, (int)gbfree, (int)gbtotal);
+		}
 	} else
-		gretq = -1;
-	if (uretq < 1 && gretq < 1) { /* no quota for this fs */
+		gret = 0;
+	if (uret < 1 && gret < 1) { /* no quota for this fs */
 		return AFPERR_PARAM;
 	}
-	if (uretq < 1) {
-		/* use group quotas */
+	if (uret < 1) {
+		/* no user quotas, but group quotas; use them */
 		*bfree = gbfree;
 		*btotal = gbtotal;
-	} else if (gretq < 1) {
-		/* use user quotas */
+	} else if (gret < 1) {
+		/* no group quotas, but user quotas; use them */
 		*bfree = ubfree;
 		*btotal = ubtotal;
 	} else {
-		/* return smallest remaining space of user and group */
+		/* both; return smallest remaining space of user and group */
 		if (ubfree < gbfree) {
 			*bfree = ubfree;
 			*btotal = ubtotal;
