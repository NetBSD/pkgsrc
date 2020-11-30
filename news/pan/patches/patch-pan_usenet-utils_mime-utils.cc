$NetBSD: patch-pan_usenet-utils_mime-utils.cc,v 1.5 2020/11/30 13:06:40 nia Exp $

NetBSD iconv's argument is no longer const.

--- pan/usenet-utils/mime-utils.cc.orig	2019-09-29 21:01:34.000000000 +0000
+++ pan/usenet-utils/mime-utils.cc
@@ -17,6 +17,13 @@
  *
  */
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV
+#endif
+#endif
+
 #include <config.h>
 #include <cctype>
 #include <cstring>
@@ -77,7 +84,7 @@ namespace pan
       outbuf = out + converted;
       outleft = outlen - converted;
 
-#if defined(__NetBSD__)
+#if (defined(__NetBSD__) && !defined(NETBSD_POSIX_ICONV)) || defined(__sun)
       converted = iconv (cd, &inbuf, &inleft, &outbuf, &outleft);
 #else
       converted = iconv (cd, (char **) &inbuf, &inleft, &outbuf, &outleft);
