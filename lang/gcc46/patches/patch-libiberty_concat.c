$NetBSD: patch-libiberty_concat.c,v 1.1 2016/09/06 13:57:02 maya Exp $

use stdarg, not VA_* macros.
cherry picked necessary parts from
https://gcc.gnu.org/viewcvs/gcc?view=revision&revision=206881

fixes PR pkg/50042

--- libiberty/concat.c.orig	2011-02-03 07:23:20.000000000 +0000
+++ libiberty/concat.c
@@ -102,11 +90,11 @@ unsigned long
 concat_length (const char *first, ...)
 {
   unsigned long length;
+  va_list args;
 
-  VA_OPEN (args, first);
-  VA_FIXEDARG (args, const char *, first);
+  va_start (args, first);
   length = vconcat_length (first, args);
-  VA_CLOSE (args);
+  va_end (args);
 
   return length;
 }
@@ -117,13 +105,12 @@ char *
 concat_copy (char *dst, const char *first, ...)
 {
   char *save_dst;
+  va_list args;
 
-  VA_OPEN (args, first);
-  VA_FIXEDARG (args, char *, dst);
-  VA_FIXEDARG (args, const char *, first);
+  va_start (args, first);
   vconcat_copy (dst, first, args);
   save_dst = dst; /* With K&R C, dst goes out of scope here.  */
-  VA_CLOSE (args);
+  va_end (args);
 
   return save_dst;
 }
@@ -141,10 +128,10 @@ char *libiberty_concat_ptr;
 char *
 concat_copy2 (const char *first, ...)
 {
-  VA_OPEN (args, first);
-  VA_FIXEDARG (args, const char *, first);
+  va_list args;
+  va_start (args, first);
   vconcat_copy (libiberty_concat_ptr, first, args);
-  VA_CLOSE (args);
+  va_end (args);
 
   return libiberty_concat_ptr;
 }
@@ -153,18 +140,17 @@ char *
 concat (const char *first, ...)
 {
   char *newstr;
+  va_list args;
 
   /* First compute the size of the result and get sufficient memory.  */
-  VA_OPEN (args, first);
-  VA_FIXEDARG (args, const char *, first);
+  va_start (args, first);
   newstr = XNEWVEC (char, vconcat_length (first, args) + 1);
-  VA_CLOSE (args);
+  va_end (args);
 
   /* Now copy the individual pieces to the result string. */
-  VA_OPEN (args, first);
-  VA_FIXEDARG (args, const char *, first);
+  va_start (args, first);
   vconcat_copy (newstr, first, args);
-  VA_CLOSE (args);
+  va_end (args);
 
   return newstr;
 }
@@ -191,22 +177,19 @@ char *
 reconcat (char *optr, const char *first, ...)
 {
   char *newstr;
+  va_list args;
 
   /* First compute the size of the result and get sufficient memory.  */
-  VA_OPEN (args, first);
-  VA_FIXEDARG (args, char *, optr);
-  VA_FIXEDARG (args, const char *, first);
+  va_start (args, first);
   newstr = XNEWVEC (char, vconcat_length (first, args) + 1);
-  VA_CLOSE (args);
+  va_end (args);
 
   /* Now copy the individual pieces to the result string. */
-  VA_OPEN (args, first);
-  VA_FIXEDARG (args, char *, optr);
-  VA_FIXEDARG (args, const char *, first);
+  va_start (args, first);
   vconcat_copy (newstr, first, args);
   if (optr) /* Done before VA_CLOSE so optr stays in scope for K&R C.  */
     free (optr);
-  VA_CLOSE (args);
+  va_end (args);
 
   return newstr;
 }
