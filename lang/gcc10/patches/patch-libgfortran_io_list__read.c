$NetBSD: patch-libgfortran_io_list__read.c,v 1.1 2020/05/17 19:47:19 rillig Exp $

Fix -Werror=char-subscripts.

https://gcc.gnu.org/bugzilla/show_bug.cgi?id=95177

--- libgfortran/io/list_read.c.orig	2020-05-07 10:50:02.000000000 +0000
+++ libgfortran/io/list_read.c
@@ -2757,7 +2757,7 @@ nml_match_name (st_parameter_dt *dtp, co
   for (i = 0; i < len; i++)
     {
       c = next_char (dtp);
-      if (c == EOF || (tolower (c) != tolower (name[i])))
+      if (c == EOF || (tolower (c) != tolower ((unsigned char) name[i])))
 	{
 	  dtp->u.p.nml_read_error = 1;
 	  break;
