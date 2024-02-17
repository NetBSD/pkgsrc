$NetBSD: patch-lib_dpkg_color.c,v 1.1 2024/02/17 10:57:05 adam Exp $

Fix buidling.

--- lib/dpkg/color.c.orig	2024-02-17 10:31:29.644530838 +0000
+++ lib/dpkg/color.c
@@ -72,3 +72,9 @@ color_get(const char *color)
 
 	return color;
 }
+
+const char *
+color_reset(void)
+{
+        return color_get(COLOR_RESET);
+}
