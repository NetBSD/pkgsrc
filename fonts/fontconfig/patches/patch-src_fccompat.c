$NetBSD: patch-src_fccompat.c,v 1.1 2026/06/22 19:26:14 wiz Exp $

NetBSD doesn't have uselocale.
https://gitlab.freedesktop.org/fontconfig/fontconfig/-/work_items/543

--- src/fccompat.c.orig	2026-06-22 19:21:13.540675219 +0000
+++ src/fccompat.c
@@ -375,7 +375,11 @@ FcLocaleSetCurrent (FcLocale loc)
 FcLocale
 FcLocaleSetCurrent (FcLocale loc)
 {
+#ifdef __NetBSD__
+    return NULL;
+#else
     return uselocale (loc);
+#endif
 }
 #endif
 
