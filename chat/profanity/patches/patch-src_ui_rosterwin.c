$NetBSD: patch-src_ui_rosterwin.c,v 1.1 2020/09/04 10:15:17 nia Exp $

Prevent NetBSD libcurses from dereferencing a null pointer.

--- src/ui/rosterwin.c.orig	2020-06-25 13:59:14.000000000 +0000
+++ src/ui/rosterwin.c
@@ -95,7 +95,10 @@ rosterwin_roster(void)
 
     ProfLayoutSplit *layout = (ProfLayoutSplit*)console->layout;
     assert(layout->memcheck == LAYOUT_SPLIT_MEMCHECK);
-    werase(layout->subwin);
+
+    if (layout->subwin != NULL) {
+        werase(layout->subwin);
+    }
 
     char *roomspos = prefs_get_string(PREF_ROSTER_ROOMS_POS);
     if (prefs_get_boolean(PREF_ROSTER_ROOMS) && (g_strcmp0(roomspos, "first") == 0)) {
@@ -1105,9 +1108,11 @@ _rosterwin_contacts_header(ProfLayoutSpl
 
     gboolean wrap = prefs_get_boolean(PREF_ROSTER_WRAP);
 
-    wattron(layout->subwin, theme_attrs(THEME_ROSTER_HEADER));
-    win_sub_print(layout->subwin, header->str, FALSE, wrap, 1);
-    wattroff(layout->subwin, theme_attrs(THEME_ROSTER_HEADER));
+    if (layout->subwin != NULL) {
+        wattron(layout->subwin, theme_attrs(THEME_ROSTER_HEADER));
+        win_sub_print(layout->subwin, header->str, FALSE, wrap, 1);
+        wattroff(layout->subwin, theme_attrs(THEME_ROSTER_HEADER));
+    }
 
     g_string_free(header, TRUE);
 }
@@ -1165,9 +1170,11 @@ _rosterwin_rooms_header(ProfLayoutSplit 
 
     gboolean wrap = prefs_get_boolean(PREF_ROSTER_WRAP);
 
-    wattron(layout->subwin, theme_attrs(THEME_ROSTER_HEADER));
-    win_sub_print(layout->subwin, header->str, FALSE, wrap, 1);
-    wattroff(layout->subwin, theme_attrs(THEME_ROSTER_HEADER));
+    if (layout->subwin != NULL) {
+        wattron(layout->subwin, theme_attrs(THEME_ROSTER_HEADER));
+        win_sub_print(layout->subwin, header->str, FALSE, wrap, 1);
+        wattroff(layout->subwin, theme_attrs(THEME_ROSTER_HEADER));
+    }
 
     g_string_free(header, TRUE);
 }
