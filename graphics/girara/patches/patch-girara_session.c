$NetBSD: patch-girara_session.c,v 1.1 2016/12/09 08:06:50 leot Exp $

Update font handling for changes in Gtk+ 3.21
(from upstream commit 949c879aa84e9496fabc7d3602060e29f9dc42a1)

--- girara/session.c.orig	2016-04-18 20:35:34.000000000 +0000
+++ girara/session.c
@@ -44,7 +44,6 @@ init_template_engine(GiraraTemplate* css
 {
   static const char* variable_names[] = {
     "session",
-    "font",
     "default-fg",
     "default-bg",
     "inputbar-fg",
@@ -78,6 +77,88 @@ init_template_engine(GiraraTemplate* css
   for (size_t idx = 0; idx < LENGTH(variable_names); ++idx) {
     girara_template_add_variable(csstemplate, variable_names[idx]);
   }
+
+  if (gtk_check_version(3, 20, 0) == NULL) {
+    girara_template_add_variable(csstemplate, "font-family");
+    girara_template_add_variable(csstemplate, "font-size");
+    girara_template_add_variable(csstemplate, "font-weight");
+  } else {
+    girara_template_add_variable(csstemplate, "font");
+  }
+}
+
+void
+css_template_fill_font(GiraraTemplate* csstemplate, const char* font)
+{
+  if (gtk_check_version(3, 20, 0) != NULL) {
+    girara_template_set_variable_value(csstemplate, "font", font);
+    return;
+  }
+
+  PangoFontDescription* descr = pango_font_description_from_string(font);
+  if (descr == NULL) {
+    return;
+  }
+
+  girara_template_set_variable_value(csstemplate, "font-family",
+      pango_font_description_get_family(descr));
+
+  char* size = g_strdup_printf("%d%s", pango_font_description_get_size(descr) / PANGO_SCALE,
+      pango_font_description_get_size_is_absolute(descr) == FALSE ? "pt" : "");
+  girara_template_set_variable_value(csstemplate, "font-size", size);
+  g_free(size);
+
+  switch (pango_font_description_get_weight(descr)) {
+    case PANGO_WEIGHT_THIN:
+      girara_template_set_variable_value(csstemplate, "font-weight", "thin");
+      break;
+
+    case PANGO_WEIGHT_ULTRALIGHT:
+      girara_template_set_variable_value(csstemplate, "font-weight", "ultralight");
+      break;
+
+    case PANGO_WEIGHT_SEMILIGHT:
+      girara_template_set_variable_value(csstemplate, "font-weight", "light");
+      break;
+
+    case PANGO_WEIGHT_LIGHT:
+      girara_template_set_variable_value(csstemplate, "font-weight", "light");
+      break;
+
+    case PANGO_WEIGHT_BOOK:
+      girara_template_set_variable_value(csstemplate, "font-weight", "book");
+      break;
+
+    case PANGO_WEIGHT_MEDIUM:
+      girara_template_set_variable_value(csstemplate, "font-weight", "medium");
+      break;
+
+    case PANGO_WEIGHT_SEMIBOLD:
+      girara_template_set_variable_value(csstemplate, "font-weight", "semibold");
+      break;
+
+    case PANGO_WEIGHT_BOLD:
+      girara_template_set_variable_value(csstemplate, "font-weight", "bold");
+      break;
+
+    case PANGO_WEIGHT_ULTRABOLD:
+      girara_template_set_variable_value(csstemplate, "font-weight", "ultrabold");
+      break;
+
+    case PANGO_WEIGHT_HEAVY:
+      girara_template_set_variable_value(csstemplate, "font-weight", "heavy");
+      break;
+
+    case PANGO_WEIGHT_ULTRAHEAVY:
+      girara_template_set_variable_value(csstemplate, "font-weight", "ultraheavy");
+      break;
+
+    default:
+      girara_template_set_variable_value(csstemplate, "font-weight", "normal");
+      break;
+  }
+
+  pango_font_description_free(descr);
 }
 
 static void
@@ -91,10 +172,16 @@ fill_template_with_values(girara_session
   char* font = NULL;
   girara_setting_get(session, "font", &font);
   if (font != NULL) {
-    girara_template_set_variable_value(csstemplate, "font", font);
+    css_template_fill_font(csstemplate, font);
     g_free(font);
   } else {
-    girara_template_set_variable_value(csstemplate, "font", "monospace normal 9");
+    if (gtk_check_version(3, 20, 0) == NULL) {
+      girara_template_set_variable_value(csstemplate, "font-family", "monospace");
+      girara_template_set_variable_value(csstemplate, "font-size", "9pt");
+      girara_template_set_variable_value(csstemplate, "font-weight", "normal");
+    } else {
+      girara_template_set_variable_value(csstemplate, "font", "monospace normal 9");
+    }
   };
 
   /* parse color values */
