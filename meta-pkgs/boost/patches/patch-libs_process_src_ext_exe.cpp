$NetBSD: patch-libs_process_src_ext_exe.cpp,v 1.1 2024/10/04 03:26:54 ryoon Exp $

* NetBSD has no alloca.h.

--- libs/process/src/ext/exe.cpp.orig	2024-09-04 03:41:50.439541344 +0000
+++ libs/process/src/ext/exe.cpp
@@ -36,7 +36,7 @@
 #if (defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__))
 #include <sys/types.h>
 #include <sys/sysctl.h>
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <alloca.h>
 #endif
 #endif
