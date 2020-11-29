$NetBSD: patch-psi_fapi__ft.c,v 1.1 2020/11/29 22:07:25 dholland Exp $

Fix build with freetype2 2.10.3+

--- psi/fapi_ft.c~	2012-08-08 08:01:36.000000000 +0000
+++ psi/fapi_ft.c
@@ -53,6 +53,11 @@
 #include FT_IMAGE_H
 #include FT_BITMAP_H
 
+/* internal now-removed freetype2 object gs shouldn't have been using */
+#ifndef FT_CALLBACK_DEF
+#define FT_CALLBACK_DEF(decl) static decl
+#endif
+
 /* Note: structure definitions here start with FF_, which stands for 'FAPI FreeType". */
 
 typedef struct FF_server_s
