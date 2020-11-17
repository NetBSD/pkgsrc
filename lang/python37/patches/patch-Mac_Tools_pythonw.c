$NetBSD: patch-Mac_Tools_pythonw.c,v 1.1 2020/11/17 19:33:26 sjmulder Exp $

Support for macOS 11 and Apple Silicon (ARM). Mostly backported from:
https://github.com/python/cpython/pull/22855

--- Mac/Tools/pythonw.c.orig	2020-08-15 05:20:16.000000000 +0000
+++ Mac/Tools/pythonw.c
@@ -95,9 +95,6 @@ setup_spawnattr(posix_spawnattr_t* spawn
     size_t count;
     cpu_type_t cpu_types[1];
     short flags = 0;
-#ifdef __LP64__
-    int   ch;
-#endif
 
     if ((errno = posix_spawnattr_init(spawnattr)) != 0) {
         err(2, "posix_spawnattr_int");
@@ -119,10 +116,16 @@ setup_spawnattr(posix_spawnattr_t* spawn
 
 #elif defined(__ppc__)
     cpu_types[0] = CPU_TYPE_POWERPC;
+
 #elif defined(__i386__)
     cpu_types[0] = CPU_TYPE_X86;
+
+#elif defined(__arm64__)
+    cpu_types[0] = CPU_TYPE_ARM64;
+
 #else
 #       error "Unknown CPU"
+
 #endif
 
     if (posix_spawnattr_setbinpref_np(spawnattr, count,
@@ -220,7 +223,8 @@ main(int argc, char **argv) {
     /* We're weak-linking to posix-spawnv to ensure that
      * an executable build on 10.5 can work on 10.4.
      */
-    if (posix_spawn != NULL) {
+
+    if (&posix_spawn != NULL) {
         posix_spawnattr_t spawnattr = NULL;
 
         setup_spawnattr(&spawnattr);
