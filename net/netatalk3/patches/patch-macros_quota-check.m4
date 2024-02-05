$NetBSD: patch-macros_quota-check.m4,v 1.3 2024/02/05 15:02:16 hauke Exp $

NetBSD flavor of quota

--- macros/quota-check.m4.orig	2023-10-05 11:12:30.000000000 +0000
+++ macros/quota-check.m4
@@ -21,13 +21,9 @@ AC_DEFUN([AC_NETATALK_CHECK_QUOTA], [
 			QUOTA_LIBS=""
 			netatalk_cv_quotasupport="yes"
 			AC_CHECK_LIB(rpcsvc, main, [QUOTA_LIBS="-lrpcsvc"])
-			AC_CHECK_HEADERS([rpc/rpc.h rpc/pmap_prot.h rpcsvc/rquota.h],[],[
-				QUOTA_LIBS=""
-				netatalk_cv_quotasupport="no"
-				AC_DEFINE(NO_QUOTA_SUPPORT, 1, [Define if quota support should not compiled])
-			])
-			AC_CHECK_LIB(quota, getfsquota, [QUOTA_LIBS="-lquota -lprop -lrpcsvc"
-				AC_DEFINE(HAVE_LIBQUOTA, 1, [define if you have libquota])], [], [-lprop -lrpcsvc])
+			AC_CHECK_HEADERS([rpc/rpc.h rpc/pmap_prot.h rpcsvc/rquota.h],[],[])
+			AC_CHECK_LIB(quota, quota_open, [QUOTA_LIBS="-lquota -lrpcsvc"
+	    		AC_DEFINE(HAVE_LIBQUOTA, 1, [define if you have libquota])], [], [-lrpcsvc])
 		fi
 	else
 		netatalk_cv_quotasupport="no"
