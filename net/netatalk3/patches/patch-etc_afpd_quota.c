$NetBSD: patch-etc_afpd_quota.c,v 1.4 2023/04/04 18:16:06 bouyer Exp $

SunOS derivatives need to explicitely include mntent.h for MNTTYPE_NFS

NetBSD uses a different quota API.

--- etc/afpd/quota.c.orig	2023-01-10 10:49:51.000000000 +0100
+++ etc/afpd/quota.c	2023-03-29 15:54:28.917646712 +0200
@@ -21,6 +21,10 @@
 #include <unistd.h>
 #include <fcntl.h>
 
+#if defined(HAVE_SYS_MNTTAB_H) || defined(__svr4__)
+#include <sys/mntent.h>
+#endif
+
 #include <atalk/logger.h>
 #include <atalk/afp.h>
 #include <atalk/compat.h>
@@ -32,14 +36,17 @@
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
@@ -48,33 +55,64 @@
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
+
+	 seteuid( prevuid );
 
-	if (retq < 1)
-		return retq;
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
 	}
+	else {
+		*bfree = dbtob(qv.qv_hardlimit - qv.qv_usage);
+		*btotal = dbtob(qv.qv_hardlimit);
+	}
+
 	return 1;
 }
 
@@ -85,12 +123,12 @@
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
