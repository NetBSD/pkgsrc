$NetBSD: patch-MP_code_qcommon_q__platform.h,v 1.1 2019/11/17 17:56:48 nia Exp $

Always call it x86_64 regardless of operating system.

--- MP/code/qcommon/q_platform.h.orig	2019-03-16 18:09:48.000000000 +0000
+++ MP/code/qcommon/q_platform.h
@@ -226,7 +226,7 @@ Foundation, Inc., 51 Franklin St, Fifth 
 #elif defined __amd64__
 #undef idx64
 #define idx64 1
-#define ARCH_STRING "amd64"
+#define ARCH_STRING "x86_64"
 #elif defined __axp__
 #define ARCH_STRING "alpha"
 #endif
