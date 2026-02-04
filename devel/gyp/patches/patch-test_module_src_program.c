$NetBSD: patch-test_module_src_program.c,v 1.2 2026/02/04 00:06:54 wiz Exp $

Treat other targets than Windows the same,
don't require explicit platform code here.

--- test/module/src/program.c.orig	2026-02-04 00:01:38.000000000 +0000
+++ test/module/src/program.c
@@ -3,7 +3,7 @@
 
 #if defined(PLATFORM_WIN)
 #include <windows.h>
-#elif defined(PLATFORM_MAC) || defined(PLATFORM_LINUX)
+#else
 #include <dlfcn.h>
 #include <libgen.h>
 #include <string.h>
@@ -13,10 +13,8 @@
 
 #if defined(PLATFORM_WIN)
 #define MODULE_SUFFIX ".dll"
-#elif defined(PLATFORM_MAC)
+#else
 #define MODULE_SUFFIX ".so"
-#elif defined(PLATFORM_LINUX)
-#define MODULE_SUFFIX ".so"
 #endif
 
 typedef void (*module_symbol)(void);
@@ -56,7 +54,7 @@ void CallModule(const char* module) {
   funcptr();
 
   FreeLibrary(dl);
-#elif defined(PLATFORM_MAC) || defined(PLATFORM_LINUX)
+#else
   void* dl;
   char* path_copy = strdup(bin_path);
   char* bin_dir = dirname(path_copy);
@@ -96,7 +94,7 @@ int main(int argc, char *argv[])
     fprintf(stderr, "Failed to determine executable path.\n");
     return 1;
   }
-#elif defined(PLATFORM_MAC) || defined(PLATFORM_LINUX)
+#else
   // Using argv[0] should be OK here since we control how the tests run, and
   // can avoid exec and such issues that make it unreliable.
   if (!realpath(argv[0], bin_path)) {
