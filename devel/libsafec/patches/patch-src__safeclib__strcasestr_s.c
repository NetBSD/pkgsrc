$NetBSD: patch-src__safeclib__strcasestr_s.c,v 1.1.1.1 2014/11/09 01:52:24 agc Exp $

patch for ctype macro args - how was this "safe" in the first place?

--- src/safeclib/strcasestr_s.c	2014/11/09 01:39:40	1.1
+++ src/safeclib/strcasestr_s.c	2014/11/09 01:40:08
@@ -153,7 +153,7 @@
         while (dest[i] && dlen) {
 
             /* not a match, not a substring */
-            if (toupper(dest[i]) != toupper(src[i])) {
+            if (toupper((unsigned char)dest[i]) != toupper((unsigned char)src[i])) {
                 break;
             }
 
