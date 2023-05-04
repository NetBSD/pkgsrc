$NetBSD: patch-etc_afpd_quota.c,v 1.5 2023/05/04 16:53:07 hauke Exp $

NetBSD uses a different quota API.

--- etc/afpd/quota.c.orig	2023-04-28 05:16:02.000000000 +0000
+++ etc/afpd/quota.c
@@ -36,14 +36,17 @@
 #include "unix.h"
 
 #ifdef HAVE_LIBQUOTA
-#include <quota/quota.h>
+#include <quota.h>
 
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
@@ -52,33 +55,64 @@ getfreespace(const AFPObj *obj, struct v
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
 	}
 
-    unbecome_root();
+	quota_close(qh);
 
-	if (retq < 1)
-		return retq;
+	 seteuid( prevuid );
+
+	if (qv.qv_usage >= qv.qv_hardlimit ||
+            (qv.qv_usage >= qv.qv_softlimit && now > qv.qv_expiretime)) {
 
-	switch(QL_STATUS(quota_check_limit(ufsq[QUOTA_LIMIT_BLOCK].ufsqe_cur, 1,
-	    ufsq[QUOTA_LIMIT_BLOCK].ufsqe_softlimit,
-	    ufsq[QUOTA_LIMIT_BLOCK].ufsqe_hardlimit,
-	    ufsq[QUOTA_LIMIT_BLOCK].ufsqe_time, now))) {
-	case QL_S_DENY_HARD:
-	case QL_S_DENY_GRACE:
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
 	}
+
 	return 1;
 }
 
@@ -89,12 +123,12 @@ int uquota_getvolspace(const AFPObj *obj
 	VolSpace gbfree, gbtotal;
 
 	uretq = getfreespace(obj, vol, &ubfree, &ubtotal,
-			     uuid, QUOTADICT_CLASS_USER);
-	LOG(log_info, logtype_afpd, "getfsquota(%s): %d %d",
+			     obj->uid, QUOTA_IDTYPE_USER);
+	LOG(log_info, logtype_afpd, "getfreespace(%s): %d %d",
 	    vol->v_path, (int)ubfree, (int)ubtotal);
 	if (obj->ngroups >= 1) {
-		gretq = getfreespace(vol, &ubfree, &ubtotal,
-		    obj->groups[0], QUOTADICT_CLASS_GROUP);
+		gretq = getfreespace(obj, vol, &ubfree, &ubtotal,
+		    obj->groups[0], QUOTA_IDTYPE_GROUP);
 	} else
 		gretq = -1;
 	if (uretq < 1 && gretq < 1) { /* no quota for this fs */
