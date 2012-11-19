$NetBSD: patch-src_engine.c,v 1.2 2012/11/19 23:15:53 joerg Exp $

* for ibus-1.4

--- src/engine.c.orig	2009-10-18 17:06:12.000000000 +0000
+++ src/engine.c
@@ -79,7 +79,7 @@ static void ibus_array_engine_show_speci
 static void ibus_config_value_changed (IBusConfig *config, 
                                         const gchar *section, 
                                         const gchar *name, 
-                                        GValue *value, 
+                                        GVariant *value, 
                                         gpointer user_data);
 
 static IBusEngineClass *parent_class = NULL;
@@ -120,7 +120,7 @@ void 
 ibus_array_init (IBusBus *bus) 
 {
     gboolean res;
-    GValue value = { 0, };
+    GVariant *value = NULL;
 
     array_context = array_create_context();
 
@@ -129,20 +129,22 @@ ibus_array_init (IBusBus *bus) 
     is_special_notify = FALSE;
     is_special_only = FALSE;
 
-    res = ibus_config_get_value (config, "engine/Array", 
-                                "SpecialNotify", &value);
+    res = ((value = ibus_config_get_value (config, "engine/Array", 
+                                "SpecialNotify")) != NULL);
     if (res) {
-        const gchar* str = g_value_get_string(&value);
+        const gchar* str = g_variant_get_string(value, NULL);
         if (g_strcmp0(str, "1") == 0)
             is_special_notify = TRUE;
+        g_variant_unref(value);
     }
 
-    res = ibus_config_get_value (config, "engine/Array", 
-                                "SpecialOnly", &value);
+    res = ((value = ibus_config_get_value (config, "engine/Array", 
+                                "SpecialOnly")) != NULL);
     if (res) {
-        const gchar* str = g_value_get_string(&value);
+        const gchar* str = g_variant_get_string(value, NULL);
         if (g_strcmp0(str, "1") == 0)
             is_special_only = TRUE;
+        g_variant_unref(value);
     }
 }
 
@@ -349,7 +351,7 @@ ibus_array_engine_update_symbol_lookup_t
 
     if (arrayeng->preedit->len == 0) {
         ibus_engine_hide_lookup_table ((IBusEngine *) arrayeng);
-        return;
+        return FALSE;
     }
 
     ibus_lookup_table_clear (arrayeng->table);
@@ -360,12 +362,12 @@ ibus_array_engine_update_symbol_lookup_t
     
     if (candidates == NULL) {
         ibus_engine_hide_lookup_table ((IBusEngine *) arrayeng);
-        return;
+        return FALSE;
     }
     else if (candidates->len == 0) {
         array_release_candidates(candidates);
         ibus_engine_hide_lookup_table ((IBusEngine *) arrayeng);
-        return;
+        return FALSE;
     }
 
     for (i = 0; i < candidates->len; i++) {
@@ -754,14 +756,14 @@ static void ibus_array_engine_property_a
 static void ibus_config_value_changed (IBusConfig *config, 
                                         const gchar *section, 
                                         const gchar *name, 
-                                        GValue *value, 
+                                        GVariant *value, 
                                         gpointer user_data)
 {
     IBusArrayEngine *arrayeng = (IBusArrayEngine*)user_data;
 
     if (g_strcmp0(section, "engine/Array") == 0) {
         if (g_strcmp0(name, "SpecialNotify") == 0) {
-            const gchar* str = g_value_get_string(value);
+            const gchar* str = g_variant_get_string(value, NULL);
             if (g_strcmp0(str, "1") == 0) {
                 is_special_notify = TRUE;
             }
@@ -770,7 +772,7 @@ static void ibus_config_value_changed (I
             }
         }
         else if (g_strcmp0(name, "SpecialOnly") == 0) {
-            const gchar* str = g_value_get_string(value);
+            const gchar* str = g_variant_get_string(value, NULL);
             if (g_strcmp0(str, "1") == 0) {
                 is_special_only = TRUE;
             }
