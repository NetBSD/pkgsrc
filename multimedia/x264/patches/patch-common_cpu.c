$NetBSD: patch-common_cpu.c,v 1.2 2025/11/29 19:16:03 martin Exp $

Add support for NetBSD/macppc altivec discovery

--- cpu.c.orig	2023-10-01 16:28:26.000000000 +0200
+++ cpu.c	2025-11-29 18:58:01.556075806 +0100
@@ -40,7 +40,7 @@
 #if SYS_BEOS
 #include <kernel/OS.h>
 #endif
-#if SYS_MACOSX || SYS_OPENBSD || SYS_FREEBSD
+#if SYS_MACOSX || SYS_OPENBSD || SYS_FREEBSD || SYS_NETBSD
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
@@ -305,7 +305,7 @@
 
 #elif HAVE_ALTIVEC
 
-#if SYS_MACOSX || SYS_OPENBSD || SYS_FREEBSD
+#if SYS_MACOSX || SYS_OPENBSD || SYS_FREEBSD || SYS_NETBSD
 
 uint32_t x264_cpu_detect( void )
 {
@@ -320,6 +320,8 @@
     size_t   length = sizeof( has_altivec );
 #if SYS_MACOSX || SYS_OPENBSD
     int      error = sysctl( selectors, 2, &has_altivec, &length, NULL, 0 );
+#elif SYS_NETBSD
+    int      error = sysctlbyname( "machdep.altivec", &has_altivec, &length, NULL, 0 );
 #else
     int      error = sysctlbyname( "hw.altivec", &has_altivec, &length, NULL, 0 );
 #endif
