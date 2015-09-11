$NetBSD: patch-src_mesa_x86_common__x86.c,v 1.2 2015/09/11 00:03:36 tnn Exp $

DragonFly support.

--- src/mesa/x86/common_x86.c.orig	2015-07-14 18:10:47.000000000 +0000
+++ src/mesa/x86/common_x86.c
@@ -38,7 +38,7 @@
 #if defined(USE_SSE_ASM) && defined(__linux__)
 #include <linux/version.h>
 #endif
-#if defined(USE_SSE_ASM) && defined(__FreeBSD__)
+#if defined(USE_SSE_ASM) && (defined(__FreeBSD__) || defined(__DragonFly__))
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
@@ -128,7 +128,7 @@ static LONG WINAPI ExceptionFilter(LPEXC
  */
 void _mesa_check_os_sse_support( void )
 {
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
    {
       int ret, enabled;
       unsigned int len;
