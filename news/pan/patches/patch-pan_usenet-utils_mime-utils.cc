$NetBSD: patch-pan_usenet-utils_mime-utils.cc,v 1.2 2012/07/13 08:16:00 marino Exp $

Fix build with NetBSD's iconv().

--- pan/usenet-utils/mime-utils.cc.orig	2012-06-29 22:24:54.000000000 +0000
+++ pan/usenet-utils/mime-utils.cc
@@ -77,7 +77,11 @@ namespace pan
       outbuf = out + converted;
       outleft = outlen - converted;
 
+#if defined(__NetBSD__)
+      converted = iconv (cd, (const char **) &inbuf, &inleft, &outbuf, &outleft);
+#else
       converted = iconv (cd, (char **) &inbuf, &inleft, &outbuf, &outleft);
+#endif
 
       if (converted != (size_t) -1 && errno == 0) {
         /*
