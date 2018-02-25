$NetBSD: patch-common_cpu.c,v 1.1 2018/02/25 21:57:43 adam Exp $

Add support for NetBSD.

--- common/cpu.c.orig	2018-02-07 08:18:42.000000000 +0000
+++ common/cpu.c
@@ -37,7 +37,7 @@
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
-#if SYS_OPENBSD
+#if SYS_OPENBSD || SYS_NETBSD
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #include <machine/cpu.h>
@@ -300,20 +300,20 @@ uint32_t x264_cpu_detect( void )
 
 #elif ARCH_PPC && HAVE_ALTIVEC
 
-#if SYS_MACOSX || SYS_OPENBSD || SYS_FREEBSD
+#if SYS_MACOSX || SYS_OPENBSD || SYS_NETBSD || SYS_FREEBSD
 #include <sys/sysctl.h>
 uint32_t x264_cpu_detect( void )
 {
     /* Thank you VLC */
     uint32_t cpu = 0;
-#if SYS_OPENBSD
+#if SYS_OPENBSD || SYS_NETBSD
     int      selectors[2] = { CTL_MACHDEP, CPU_ALTIVEC };
 #elif SYS_MACOSX
     int      selectors[2] = { CTL_HW, HW_VECTORUNIT };
 #endif
     int      has_altivec = 0;
     size_t   length = sizeof( has_altivec );
-#if SYS_MACOSX || SYS_OPENBSD
+#if SYS_MACOSX || SYS_OPENBSD || SYS_NETBSD
     int      error = sysctl( selectors, 2, &has_altivec, &length, NULL, 0 );
 #else
     int      error = sysctlbyname( "hw.altivec", &has_altivec, &length, NULL, 0 );
@@ -462,10 +462,10 @@ int x264_cpu_num_processors( void )
     get_system_info( &info );
     return info.cpu_count;
 
-#elif SYS_MACOSX || SYS_FREEBSD || SYS_OPENBSD
+#elif SYS_MACOSX || SYS_FREEBSD || SYS_OPENBSD || SYS_NETBSD
     int ncpu;
     size_t length = sizeof( ncpu );
-#if SYS_OPENBSD
+#if SYS_OPENBSD || SYS_NETBSD
     int mib[2] = { CTL_HW, HW_NCPU };
     if( sysctl(mib, 2, &ncpu, &length, NULL, 0) )
 #else
