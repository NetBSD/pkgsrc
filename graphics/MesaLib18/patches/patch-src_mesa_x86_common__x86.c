$NetBSD: patch-src_mesa_x86_common__x86.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

DragonFly support.

--- src/mesa/x86/common_x86.c.orig	2017-05-10 14:13:58.000000000 +0000
+++ src/mesa/x86/common_x86.c
@@ -35,7 +35,7 @@
  */
 
 /* XXX these includes should probably go into imports.h or glheader.h */
-#if defined(USE_SSE_ASM) && defined(__FreeBSD__)
+#if defined(USE_SSE_ASM) && (defined(__FreeBSD__) || defined(__DragonFly__))
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
@@ -125,7 +125,7 @@ static LONG WINAPI ExceptionFilter(LPEXC
  */
 void _mesa_check_os_sse_support( void )
 {
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
    {
       int ret, enabled;
       unsigned int len;
