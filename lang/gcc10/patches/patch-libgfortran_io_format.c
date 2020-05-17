$NetBSD: patch-libgfortran_io_format.c,v 1.1 2020/05/17 19:47:19 rillig Exp $

Fix -Werror=char-subscripts.

https://gcc.gnu.org/bugzilla/show_bug.cgi?id=95177

--- libgfortran/io/format.c.orig	2020-05-07 10:50:02.000000000 +0000
+++ libgfortran/io/format.c
@@ -193,7 +193,7 @@ next_char (format_data *fmt, int literal
 	return -1;
 
       fmt->format_string_len--;
-      c = toupper (*fmt->format_string++);
+      c = toupper ((unsigned char) *fmt->format_string++);
       fmt->error_element = c;
     }
   while ((c == ' ' || c == '\t') && !literal);
