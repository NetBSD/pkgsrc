$NetBSD: patch-macros_quota-check.m4,v 1.1 2014/06/11 11:03:57 hauke Exp $

--- macros/quota-check.m4.orig	2013-06-24 16:47:02.000000000 +0000
+++ macros/quota-check.m4
@@ -9,13 +9,9 @@ AC_DEFUN([AC_NETATALK_CHECK_QUOTA], [
 	QUOTA_LIBS=""
 	netatalk_cv_quotasupport="yes"
 	AC_CHECK_LIB(rpcsvc, main, [QUOTA_LIBS="-lrpcsvc"])
-	AC_CHECK_HEADERS([rpc/rpc.h rpc/pmap_prot.h rpcsvc/rquota.h],[],[
-		QUOTA_LIBS=""
-		netatalk_cv_quotasupport="no"
-		AC_DEFINE(NO_QUOTA_SUPPORT, 1, [Define if quota support should not compiled])
-	])
-	AC_CHECK_LIB(quota, getfsquota, [QUOTA_LIBS="-lquota -lprop -lrpcsvc"
-	    AC_DEFINE(HAVE_LIBQUOTA, 1, [define if you have libquota])], [], [-lprop -lrpcsvc])
+	AC_CHECK_HEADERS([rpc/rpc.h rpc/pmap_prot.h rpcsvc/rquota.h],[],[])
+	AC_CHECK_LIB(quota, quota_open, [QUOTA_LIBS="-lquota -lrpcsvc"
+	    AC_DEFINE(HAVE_LIBQUOTA, 1, [define if you have libquota])], [], [-lrpcsvc])
 	else
 		netatalk_cv_quotasupport="no"
 		AC_DEFINE(NO_QUOTA_SUPPORT, 1, [Define if quota support should not compiled])
