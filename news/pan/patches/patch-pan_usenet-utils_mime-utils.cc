$NetBSD: patch-pan_usenet-utils_mime-utils.cc,v 1.1 2012/04/09 23:00:49 wiz Exp $

Fix build with NetBSD's iconv().

--- pan/usenet-utils/mime-utils.cc.orig	2012-04-08 15:30:36.000000000 +0000
+++ pan/usenet-utils/mime-utils.cc
@@ -77,7 +77,7 @@ namespace pan
       outbuf = out + converted;
       outleft = outlen - converted;
 
-      converted = iconv (cd, (char **) &inbuf, &inleft, &outbuf, &outleft);
+      converted = iconv (cd, (const char **) &inbuf, &inleft, &outbuf, &outleft);
 
       if (converted != (size_t) -1 && errno == 0) {
         /*
