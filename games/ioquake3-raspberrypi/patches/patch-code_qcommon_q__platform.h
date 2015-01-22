$NetBSD: patch-code_qcommon_q__platform.h,v 1.1 2015/01/22 12:51:00 jmcneill Exp $

--- code/qcommon/q_platform.h.orig	2014-11-03 15:11:07.000000000 +0000
+++ code/qcommon/q_platform.h
@@ -199,6 +199,8 @@ Foundation, Inc., 51 Franklin St, Fifth 
 
 #ifdef __i386__
 #define ARCH_STRING "i386"
+#elif defined __arm__
+#define ARCH_STRING "rpi"
 #elif defined __axp__
 #define ARCH_STRING "alpha"
 #endif
