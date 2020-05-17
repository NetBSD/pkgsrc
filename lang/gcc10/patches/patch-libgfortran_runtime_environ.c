$NetBSD: patch-libgfortran_runtime_environ.c,v 1.1 2020/05/17 19:47:20 rillig Exp $

Fix -Werror=char-subscripts.

https://gcc.gnu.org/bugzilla/show_bug.cgi?id=95177

--- libgfortran/runtime/environ.c.orig	2020-05-07 10:50:02.000000000 +0000
+++ libgfortran/runtime/environ.c
@@ -91,7 +91,7 @@ init_integer (variable * v)
     return;
 
   for (q = p; *q; q++)
-    if (!isdigit (*q) && (p != q || *q != '-'))
+    if (!isdigit ((unsigned char) *q) && (p != q || *q != '-'))
       return;
 
   *v->var = atoi (p);
@@ -344,7 +344,7 @@ static int
 match_integer (void)
 {
   unit_num = 0;
-  while (isdigit (*p))
+  while (isdigit ((unsigned char) *p))
     unit_num = unit_num * 10 + (*p++ - '0');
   return INTEGER;
 }
