$NetBSD: patch-common_cpu.c,v 1.1 2022/12/18 09:07:24 martin Exp $

Add support for NetBSD/macppc altivec discovery

--- common/cpu.c.orig	2022-12-18 09:53:44.331288779 +0100
+++ common/cpu.c	2022-12-18 10:00:12.985921601 +0100
@@ -305,7 +305,7 @@ uint32_t x264_cpu_detect( void )
 
 #elif HAVE_ALTIVEC
 
-#if SYS_MACOSX || SYS_OPENBSD || SYS_FREEBSD
+#if SYS_MACOSX || SYS_OPENBSD || SYS_FREEBSD || SYS_NETBSD
 
 uint32_t x264_cpu_detect( void )
 {
@@ -320,6 +320,8 @@ uint32_t x264_cpu_detect( void )
     size_t   length = sizeof( has_altivec );
 #if SYS_MACOSX || SYS_OPENBSD
     int      error = sysctl( selectors, 2, &has_altivec, &length, NULL, 0 );
+#elif SYS_NETBSD
+    int      error = sysctlbyname( "machdep.altivec", &has_altivec, &length, NULL, 0 );
 #else
     int      error = sysctlbyname( "hw.altivec", &has_altivec, &length, NULL, 0 );
 #endif
