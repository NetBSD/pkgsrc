$NetBSD: patch-simgear_misc_strutils.cxx,v 1.2 2021/02/25 10:22:14 nia Exp $

Support NetBSD.

--- simgear/misc/strutils.cxx.orig	2021-01-23 18:01:02.000000000 +0000
+++ simgear/misc/strutils.cxx
@@ -1170,7 +1170,7 @@ std::string error_string(int errnum)
   retcode = strerror_s(buf, sizeof(buf), errnum);
 #elif defined(_GNU_SOURCE)
   return std::string(strerror_r(errnum, buf, sizeof(buf)));
-#elif (_POSIX_C_SOURCE >= 200112L) || defined(SG_MAC) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif (_POSIX_C_SOURCE >= 200112L) || defined(SG_MAC) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
   int retcode;
   // POSIX.1-2001 and POSIX.1-2008
   retcode = strerror_r(errnum, buf, sizeof(buf));
