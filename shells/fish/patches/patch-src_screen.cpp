$NetBSD: patch-src_screen.cpp,v 1.1.2.2 2017/10/28 18:56:04 spz Exp $

--- src/screen.cpp.orig	2017-06-03 12:45:13.000000000 +0000
+++ src/screen.cpp
@@ -215,7 +215,7 @@ static bool is_color_escape_seq(const wc
 
     // Detect these terminfo color escapes with parameter value up to max_colors, all of which
     // don't move the cursor.
-    char *const esc[] = {
+    const char *const esc[] = {
         set_a_foreground, set_a_background, set_foreground, set_background,
     };
 
@@ -238,7 +238,7 @@ static bool is_color_escape_seq(const wc
 /// displayed other than the color.
 static bool is_visual_escape_seq(const wchar_t *code, size_t *resulting_length) {
     if (!cur_term) return false;
-    char *const esc2[] = {
+    const char *const esc2[] = {
         enter_bold_mode,      exit_attribute_mode,    enter_underline_mode,  exit_underline_mode,
         enter_standout_mode,  exit_standout_mode,     flash_screen,          enter_subscript_mode,
         exit_subscript_mode,  enter_superscript_mode, exit_superscript_mode, enter_blink_mode,
@@ -506,7 +506,7 @@ static void s_move(screen_t *s, data_buf
     int i;
     int x_steps, y_steps;
 
-    char *str;
+    const char *str;
     /*
       debug( 0, L"move from %d %d to %d %d",
       s->screen_cursor[0], s->screen_cursor[1],
@@ -540,7 +540,7 @@ static void s_move(screen_t *s, data_buf
         x_steps = 0;
     }
 
-    char *multi_str = NULL;
+    const char *multi_str = NULL;
     if (x_steps < 0) {
         str = cursor_left;
         multi_str = parm_left_cursor;
@@ -594,7 +594,7 @@ static void s_write_char(screen_t *s, da
 }
 
 /// Send the specified string through tputs and append the output to the specified buffer.
-static void s_write_mbs(data_buffer_t *b, char *s) {
+static void s_write_mbs(data_buffer_t *b, const char *s) {
     scoped_buffer_t scoped_buffer(b);
     writembs(s);
 }
