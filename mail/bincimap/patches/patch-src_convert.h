$NetBSD: patch-src_convert.h,v 1.1 2021/01/15 19:50:25 schmonz Exp $

Fix "assigning to 'char *' from incompatible type 'const char *'".

--- src/convert.h.orig	2005-02-08 20:30:22.000000000 +0000
+++ src/convert.h
@@ -111,7 +111,7 @@ namespace Binc {
       unsigned char c = *i;
       unsigned char d = *(i + 1);
       
-      char *t;
+      const char *t;
       if ((t = strchr(hexchars, c)) == 0)
 	return "out of range";
       n = (t - hexchars) << 4;
