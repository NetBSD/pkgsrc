$NetBSD: patch-lib_dpkg_color.h,v 1.1 2024/02/17 10:57:05 adam Exp $

Fix building.

--- lib/dpkg/color.h.orig	2024-02-17 10:29:39.620234187 +0000
+++ lib/dpkg/color.h
@@ -74,11 +74,8 @@ color_set_mode(const char *mode);
 const char *
 color_get(const char *color);
 
-static inline const char *
-color_reset(void)
-{
-	return color_get(COLOR_RESET);
-}
+const char *
+color_reset(void);
 
 /** @} */
 
