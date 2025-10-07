$NetBSD: patch-aczsh.m4,v 1.3 2025/10/07 03:34:29 ryoon Exp $

* For more strict check by GCC 14.

--- aczsh.m4.orig	2025-10-07 01:32:32.704002119 +0000
+++ aczsh.m4
@@ -44,6 +44,7 @@ AC_DEFUN(zsh_64_BIT_TYPE,
 #include <sys/types.h>
 #endif
 
+int
 main()
 {
   $1 foo = 0; 
@@ -146,6 +147,7 @@ char *zsh_gl_sym_addr ;
 #define RTLD_GLOBAL 0
 #endif
 
+int
 main()
 {
     void *handle1, *handle2;
@@ -229,6 +231,7 @@ char *zsh_gl_sym_addr ;
 #endif
 
 
+int
 main()
 {
     void *handle1, *handle2;
@@ -304,6 +307,7 @@ char *zsh_gl_sym_addr ;
 #define RTLD_GLOBAL 0
 #endif
 
+int
 main()
 {
     void *handle;
@@ -374,6 +378,7 @@ char *zsh_gl_sym_addr ;
 #define RTLD_GLOBAL 0
 #endif
 
+int
 main()
 {
     void *handle;
@@ -448,6 +453,7 @@ char *zsh_gl_sym_addr ;
 #define RTLD_GLOBAL 0
 #endif
 
+int
 main()
 {
     void *handle;
@@ -516,6 +522,7 @@ char *zsh_gl_sym_addr ;
 #define RTLD_GLOBAL 0
 #endif
 
+int
 main()
 {
     void *handle;
