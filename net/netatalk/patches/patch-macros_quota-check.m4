$NetBSD: patch-macros_quota-check.m4,v 1.1.4.1 2012/05/14 12:24:22 tron Exp $

- do not disable quota support if some of rpc/rpc.h, rpc/pmap_prot.h,
  rpcsvc/rquota.h are missing.

- fix libquota test to check for the netbsd-6 release quota API, not
  the prerelease proplib-based API in 5.99 that got removed before
  netbsd-6.

This logic should probably be simplified, and expanded some to
simplify the mess of quota-related ifdefs in the source; the rquotad
support connected to the rpc headers and -lrpcsvc should be
independent of the local quota support, and can be probed for
independently. However, this needs to be coordinated with upstream,
not done in pkgsrc.

--- macros/quota-check.m4.orig	2011-08-18 12:23:44.000000000 +0000
+++ macros/quota-check.m4
@@ -10,13 +10,9 @@ AC_DEFUN([AC_CHECK_QUOTA], [
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
