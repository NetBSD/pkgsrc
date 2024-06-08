$NetBSD: patch-gcc_plugin.c,v 1.1 2024/06/08 08:38:25 cheusov Exp $

Fix build failure on Linux
https://pubs.opengroup.org/onlinepubs/9699919799/functions/dlopen.html

--- gcc/plugin.c.orig	2024-06-07 13:22:58.717044364 +0000
+++ gcc/plugin.c
@@ -677,6 +677,8 @@ try_init_one_plugin (struct plugin_name_
 
 #else // POSIX-like with dlopen()/dlsym().
 
+#include <dlfcn.h>
+
 /* We need a union to cast dlsym return value to a function pointer
    as ISO C forbids assignment between function pointer and 'void *'.
    Use explicit union instead of __extension__(<union_cast>) for
