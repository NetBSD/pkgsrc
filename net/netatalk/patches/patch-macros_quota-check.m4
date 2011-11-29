$NetBSD: patch-macros_quota-check.m4,v 1.1 2011/11/29 19:26:28 bouyer Exp $

--- macros/quota-check.m4.orig	2011-11-29 18:51:25.000000000 +0100
+++ macros/quota-check.m4	2011-11-29 18:53:09.000000000 +0100
@@ -10,11 +10,7 @@
 	QUOTA_LIBS=""
 	netatalk_cv_quotasupport="yes"
 	AC_CHECK_LIB(rpcsvc, main, [QUOTA_LIBS="-lrpcsvc"])
-	AC_CHECK_HEADERS([rpc/rpc.h rpc/pmap_prot.h rpcsvc/rquota.h],[],[
-		QUOTA_LIBS=""
-		netatalk_cv_quotasupport="no"
-		AC_DEFINE(NO_QUOTA_SUPPORT, 1, [Define if quota support should not compiled])
-	])
+	AC_CHECK_HEADERS([rpc/rpc.h rpc/pmap_prot.h rpcsvc/rquota.h],[],[])
 	AC_CHECK_LIB(quota, getfsquota, [QUOTA_LIBS="-lquota -lprop -lrpcsvc"
 	    AC_DEFINE(HAVE_LIBQUOTA, 1, [define if you have libquota])], [], [-lprop -lrpcsvc])
 	else
