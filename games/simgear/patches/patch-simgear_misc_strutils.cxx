$NetBSD: patch-simgear_misc_strutils.cxx,v 1.1 2018/08/04 04:04:28 nia Exp $

Support NetBSD.

--- simgear/misc/strutils.cxx.orig	2018-06-03 18:56:36.000000000 +0000
+++ simgear/misc/strutils.cxx
@@ -1017,7 +1017,8 @@ std::string error_string(int errnum)
   retcode = strerror_s(buf, sizeof(buf), errnum);
 #elif defined(_GNU_SOURCE)
   return std::string(strerror_r(errnum, buf, sizeof(buf)));
-#elif (_POSIX_C_SOURCE >= 200112L) || defined(SG_MAC) || defined(__FreeBSD__)
+#elif (_POSIX_C_SOURCE >= 200112L) || defined(SG_MAC) || \
+    defined(__FreeBSD__) || defined(__NetBSD__)
   int retcode;
   // POSIX.1-2001 and POSIX.1-2008
   retcode = strerror_r(errnum, buf, sizeof(buf));
