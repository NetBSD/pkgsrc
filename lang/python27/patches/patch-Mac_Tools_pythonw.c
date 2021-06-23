$NetBSD: patch-Mac_Tools_pythonw.c,v 1.1 2021/06/23 18:30:24 schmonz Exp $

macOS arm64 support, via MacPorts.

--- Mac/Tools/pythonw.c.orig	2021-06-22 19:20:03.000000000 +0000
+++ Mac/Tools/pythonw.c
@@ -114,6 +114,9 @@ setup_spawnattr(posix_spawnattr_t* spawn
 #elif defined(__x86_64__)
     cpu_types[0] = CPU_TYPE_X86_64;
 
+#elif defined(__arm64__)
+    cpu_types[0] = CPU_TYPE_ARM64;
+
 #elif defined(__ppc__)
     cpu_types[0] = CPU_TYPE_POWERPC;
 #elif defined(__i386__)
