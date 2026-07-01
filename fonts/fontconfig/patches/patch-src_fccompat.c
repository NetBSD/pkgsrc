$NetBSD: patch-src_fccompat.c,v 1.2 2026/07/01 08:07:23 wiz Exp $

NetBSD does not provide uselocale().
https://gitlab.freedesktop.org/fontconfig/fontconfig/-/work_items/543

--- src/fccompat.c.orig	2026-07-01 08:04:28.911964970 +0000
+++ src/fccompat.c
@@ -375,7 +375,12 @@ FcLocaleSetCurrent (FcLocale loc)
 FcLocale
 FcLocaleSetCurrent (FcLocale loc)
 {
+#  if HAVE_VASPRINTF_L || HAVE__VSNPRINTF_L
+    /* This function won't be used */
+    return NULL;
+#  else
     return uselocale (loc);
+#  endif
 }
 #endif
 
