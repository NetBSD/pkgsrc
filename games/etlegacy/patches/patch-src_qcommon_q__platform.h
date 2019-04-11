$NetBSD: patch-src_qcommon_q__platform.h,v 1.1 2019/04/11 20:56:34 nia Exp $

The CMake script will always produce internal libraries containing the
string "x86_64" and never "amd64", so make sure the game engine always
looks for libraries with "x86_64" in the filename.

--- src/qcommon/q_platform.h.orig	2019-01-05 19:54:35.000000000 +0000
+++ src/qcommon/q_platform.h
@@ -260,7 +260,7 @@
 #elif defined __amd64__
 #undef idx64
 #define idx64 1
-#define ARCH_STRING "amd64"
+#define ARCH_STRING "x86_64"
 #elif defined __axp__
 #define ARCH_STRING "alpha"
 #endif
