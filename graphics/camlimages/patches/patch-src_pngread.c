$NetBSD: patch-src_pngread.c,v 1.2 2026/01/20 09:45:43 wiz Exp $

Add missing header for strcmp().
Fix build with png-1.5.

--- src/pngread.c.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/pngread.c
@@ -21,6 +21,8 @@
 #include "oversized.h"
 #include <png.h>
 
+#include <string.h>
+
 #include <caml/mlvalues.h>
 #include <caml/alloc.h>
 #include <caml/memory.h>
@@ -69,7 +71,7 @@ value read_png_file_as_rgb24( name )
   }
 
   /* error handling */
-  if (setjmp(png_ptr->jmpbuf)) {
+  if (setjmp(png_jmpbuf(png_ptr))) {
     /* Free all of the memory associated with the png_ptr and info_ptr */
     png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
     fclose(fp);
@@ -134,7 +136,7 @@ value read_png_file_as_rgb24( name )
     png_set_rows(png_ptr, info_ptr, row_pointers);
 
     /* Later, we can return something */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
       /* Free all of the memory associated with the png_ptr and info_ptr */
       png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
       fclose(fp);
@@ -243,7 +245,7 @@ value read_png_file( name )
   }
 
   /* error handling */
-  if (setjmp(png_ptr->jmpbuf)) {
+  if (setjmp(png_jmpbuf(png_ptr))) {
     /* Free all of the memory associated with the png_ptr and info_ptr */
     png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
     fclose(fp);
@@ -302,7 +304,7 @@ value read_png_file( name )
     png_set_rows(png_ptr, info_ptr, row_pointers);
 
     /* Later, we can return something */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
       /* Free all of the memory associated with the png_ptr and info_ptr */
       png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
       fclose(fp);
