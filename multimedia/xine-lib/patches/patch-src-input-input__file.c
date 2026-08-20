$NetBSD: patch-src-input-input__file.c,v 1.1 2026/08/20 07:12:18 mrg Exp $

work with modern C.


--- src/input/input_file.c.orig	2023-01-25 08:03:17.000000000 -0800
+++ src/input/input_file.c	2026-08-20 00:02:57.343794081 -0700
@@ -651,7 +651,9 @@ static int file_input_strverscmp (const char *s1, cons
 /*
  * Wrapper to file_input_strverscmp() for qsort() calls, which sort mrl_t type array.
  */
-static int file_input_sortfiles_default (const xine_mrl_t *s1, const xine_mrl_t *s2) {
+static int file_input_sortfiles_default (const void *v1, const void *v2) {
+  const xine_mrl_t *s1 = v1;
+  const xine_mrl_t *s2 = v2;
   return(file_input_strverscmp(s1->mrl, s2->mrl));
 }
 
@@ -735,7 +737,7 @@ static xine_mrl_t **file_input_class_get_dir (input_cl
   int                   num_dir_files   = 0;
   int                   num_norm_files  = 0;
   int                   num_files       = -1;
-  int                 (*func) ()        = file_input_sortfiles_default;
+  int                 (*func) (const void *, const void *) = file_input_sortfiles_default;
   int                   already_tried   = 0;
   int                   show_hidden_files;
 
