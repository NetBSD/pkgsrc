$NetBSD: patch-lib_intern_lyrics_lyricswiki.c,v 1.1 2016/11/07 15:12:33 leot Exp $

Fix lyricswiki provider (from upstream and pull request #80).

--- lib/intern/lyrics/lyricswiki.c.orig	2016-05-17 11:39:52.000000000 +0000
+++ lib/intern/lyrics/lyricswiki.c
@@ -66,6 +66,8 @@ static gboolean lv_cmp_content (const gc
 #define LYR_NODE  "<div class='lyricbox"
 #define LYR_BEGIN ">"
 #define LYR_ENDIN "<!--"
+#define LYR_FOOTER "<div id=\"songfooter"
+#define LYR_CREDITS "<table"
 #define LYR_INSTRUMENTAL "/Category:Instrumental"
 #define LYR_SCRIPT_TAG "</script"
 
@@ -78,13 +80,23 @@ GList * parse_result_page (GlyrQuery * q
         node += (sizeof LYR_NODE);
         char *script_tag = strstr(node, LYR_SCRIPT_TAG);
         char *end_tag = strstr(node, LYR_ENDIN);
+        char *footer_tag = strstr(node, LYR_FOOTER);
+        char *credits_tag = strstr(node, LYR_CREDITS);
+        char *ending_tag = LYR_ENDIN;
+
+        if (footer_tag && footer_tag < end_tag) {
+            ending_tag = LYR_FOOTER;
+        }
+        if (credits_tag && credits_tag < end_tag) {
+            ending_tag = LYR_CREDITS;
+        }
 
         if(script_tag && script_tag < end_tag) {
             node = script_tag + sizeof(LYR_SCRIPT_TAG) - 1;
         }
 
         bool is_instrumental = strstr(node, LYR_INSTRUMENTAL) != NULL;
-        gchar * lyr = get_search_value (node,LYR_BEGIN,LYR_ENDIN);
+        gchar * lyr = get_search_value (node,LYR_BEGIN,ending_tag);
         gchar * beautiness_test = beautify_string (lyr);
 
         if (is_instrumental || (beautiness_test != NULL && beautiness_test[0]))
