$NetBSD: patch-src_mimeutils.c,v 1.1 2018/04/17 10:59:19 markd Exp $

Add font as valid media type

This was codified in RFC 8081, and some desktop apps are using
this now.
https://bugs.freedesktop.org/show_bug.cgi?id=105785

--- src/mimeutils.c.orig	2016-05-11 20:05:33.000000000 +0000
+++ src/mimeutils.c
@@ -52,9 +52,9 @@ static const char *known_old_fdo_media_t
   "x-directory"
 };
 
-/* Defined in RFC 2045/2046 and RFC 2077 */
+/* Defined in RFC 2045/2046, RFC 2077 and RFC 8081 */
 static const char *registered_discrete_media_types[] = {
-  "application", "audio", "image", "model", "text", "video"
+  "application", "audio", "font", "image", "model", "text", "video"
 };
 
 /* Defined in RFC 2045/2046 */
