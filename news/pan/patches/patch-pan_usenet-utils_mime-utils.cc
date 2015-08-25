$NetBSD: patch-pan_usenet-utils_mime-utils.cc,v 1.3 2015/08/25 08:29:10 richard Exp $

Fix build with NetBSD's iconv().

--- pan/usenet-utils/mime-utils.cc.orig	2012-06-29 22:24:54.000000000 +0000
+++ pan/usenet-utils/mime-utils.cc
@@ -77,7 +77,11 @@ namespace pan
       outbuf = out + converted;
       outleft = outlen - converted;
 
+#if defined(__NetBSD__) || defined (__sun)
+      converted = iconv (cd, (const char **) &inbuf, &inleft, &outbuf, &outleft);
+#else
       converted = iconv (cd, (char **) &inbuf, &inleft, &outbuf, &outleft);
+#endif
 
       if (converted != (size_t) -1 && errno == 0) {
         /*
