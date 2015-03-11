$NetBSD: patch-lib_stringlib.c,v 1.2 2015/03/11 08:40:31 wiz Exp $

Use <ctype.h> correctly.
https://github.com/sahib/glyr/issues/61

--- lib/stringlib.c~	2014-02-08 11:06:45.000000000 +0000
+++ lib/stringlib.c
@@ -927,8 +927,8 @@ static gchar * trim_in_text (gchar * str
 
         for (gsize it = 0; it < str_len; it++)
         {
-            gboolean is_space = isspace (string[it]);
-            gboolean is_lfeed = !isblank (string[it]) && is_space;
+            gboolean is_space = isspace ((unsigned char)string[it]);
+            gboolean is_lfeed = !isblank ((unsigned char)string[it]) && is_space;
 
             lfeed_ctr = (is_lfeed) ? lfeed_ctr + 1 : 0;
             space_ctr = (is_space) ? space_ctr + 1 : 0;
@@ -1011,7 +1011,7 @@ void trim_copy (gchar *input, gchar *out
     gchar c;
 
     /* skip spaces at start */
-    while (input[0] && isspace (*input) )
+    while (input[0] && isspace ((unsigned char)*input) )
     {
         ++input;
     }
@@ -1023,7 +1023,7 @@ void trim_copy (gchar *input, gchar *out
         c = * (output++) = * (input++);
 
         /* if its not a whitespace, this *could* be the last character */
-        if ( !isspace (c) )
+        if ( !isspace ((unsigned char)c) )
         {
             end = output;
         }
@@ -1050,14 +1050,14 @@ gchar * trim_nocopy (gchar * s)
     gchar * end = NULL;
 
     /* skip spaces at start */
-    while (*start && isspace (*start) )
+    while (*start && isspace ((unsigned char)*start) )
         ++start;
 
     /* iterate over the rest remebering last non-whitespace */
     char *i = start;
     while (*i)
     {
-        if ( !isspace (* (i++) ) )
+        if ( !isspace ((unsigned char) * (i++) ) )
             end = i;
     }
 
