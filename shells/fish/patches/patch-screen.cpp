$NetBSD: patch-screen.cpp,v 1.2 2015/03/18 15:03:43 joerg Exp $

--- screen.cpp.orig	2015-02-16 19:07:12.000000000 +0000
+++ screen.cpp
@@ -112,10 +112,11 @@ static size_t try_sequence(const char *s
  */
 static size_t next_tab_stop(size_t in)
 {
+    int itabs = init_tabs;
     /*
       Assume tab stops every 8 characters if undefined
     */
-    size_t tab_width = (init_tabs > 0 ? (size_t)init_tabs : 8);
+    size_t tab_width = (itabs > 0 ? (size_t)itabs : 8);
     return ((in/tab_width)+1)*tab_width;
 }
 
@@ -151,7 +152,7 @@ size_t escape_code_length(const wchar_t 
          Detect these terminfo color escapes with parameter
          value 0..7, all of which don't move the cursor
          */
-        char * const esc[] =
+        const char * const esc[] =
         {
             set_a_foreground,
             set_a_background,
@@ -183,7 +184,7 @@ size_t escape_code_length(const wchar_t 
          Detect these semi-common terminfo escapes without any
          parameter values, all of which don't move the cursor
          */
-        char * const esc2[] =
+        const char * const esc2[] =
         {
             enter_bold_mode,
             exit_attribute_mode,
@@ -604,7 +605,7 @@ static void s_move(screen_t *s, data_buf
     int i;
     int x_steps, y_steps;
 
-    char *str;
+    const char *str;
     /*
       debug( 0, L"move from %d %d to %d %d",
       s->screen_cursor[0], s->screen_cursor[1],
@@ -707,7 +708,7 @@ static void s_write_char(screen_t *s, da
    Send the specified string through tputs and append the output to
    the specified buffer.
 */
-static void s_write_mbs(data_buffer_t *b, char *s)
+static void s_write_mbs(data_buffer_t *b, const char *s)
 {
     scoped_buffer_t scoped_buffer(b);
     writembs(s);
