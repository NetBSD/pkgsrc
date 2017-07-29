$NetBSD: patch-slp__platformselect.h,v 1.1.2.2 2017/07/29 13:05:39 spz Exp $

--- slp_platformselect.h.orig	2016-12-10 23:52:06.000000000 +0000
+++ slp_platformselect.h
@@ -20,6 +20,8 @@
 #include "platform/switch_ppc_macosx.h" /* Apple MacOS X on PowerPC */
 #elif defined(__GNUC__) && defined(_ARCH_PPC) && defined(_AIX)
 #include "platform/switch_ppc_aix.h" /* gcc on AIX/PowerPC */
+#elif defined(__GNUC__) && defined(__powerpc__) && defined(__NetBSD__)
+#include "platform/switch_ppc_unix.h" /* gcc on NetBSD/powerpc */
 #elif defined(__GNUC__) && defined(sparc)
 #include "platform/switch_sparc_sun_gcc.h" /* SunOS sparc with gcc */
 #elif defined(__SUNPRO_C) && defined(sparc) && defined(sun)
