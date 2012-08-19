$NetBSD: patch-src_scim__hangul__imengine__setup.cpp,v 1.1 2012/08/19 09:04:17 obache Exp $

* Upstream SVN repo is correct, where is this codes came from?

--- src/scim_hangul_imengine_setup.cpp.orig	2012-07-08 11:52:07.000000000 +0000
+++ src/scim_hangul_imengine_setup.cpp
@@ -346,7 +346,7 @@ create_keyboard_page(GtkTooltips *toolti
     for (i = 0; i < n; i++) {
 	const char* name = hangul_ic_get_keyboard_name(i);
 #if GTK_CHECK_VERSION(2, 24, 0)
-	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo_box), NULL, name);
+	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_box), name);
 #else
 	gtk_combo_box_append_text(GTK_COMBO_BOX(combo_box), name);
 #endif
