$NetBSD: patch-src_ChezScheme_c_self-exe.c,v 1.1 2024/11/29 22:06:13 riastradh Exp $

Work around broken executable path resolution:
https://github.com/racket/racket/issues/5122

--- src/ChezScheme/c/self-exe.c.orig	2024-10-16 21:44:51.000000000 +0000
+++ src/ChezScheme/c/self-exe.c
@@ -230,9 +230,6 @@ static char *path_append(const char *s1,
 }
 
 static char *get_self_path_generic(const char *exec_file) {
-  if (strchr(exec_file, '/')) {
-    return copy_string(exec_file);
-  }
   char *pv = getenv("PATH");
   if (pv == NULL) {
     return NULL;
@@ -263,7 +260,13 @@ static char *get_self_path_generic(const
 }
 
 static char *get_process_executable_path(const char *exec_file) {
-  char *r = get_self_path_platform();
+  char *r = NULL;
+  if (strchr(exec_file, '/')) {
+    r = copy_string(exec_file);
+  }
+  if (r == NULL) {
+    r = get_self_path_platform();
+  }
   if (r == NULL) {
     r = get_self_path_generic(exec_file);
   }
