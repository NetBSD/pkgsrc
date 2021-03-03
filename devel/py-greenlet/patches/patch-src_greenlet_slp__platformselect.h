$NetBSD: patch-src_greenlet_slp__platformselect.h,v 1.1 2021/03/03 18:05:02 adam Exp $

Support NetBSD/powerpc.

--- src/greenlet/slp_platformselect.h.orig	2021-01-13 13:34:17.000000000 +0000
+++ src/greenlet/slp_platformselect.h
@@ -22,6 +22,8 @@
 #include "platform/switch_ppc64_aix.h" /* gcc on AIX/PowerPC 64-bit */
 #elif defined(__GNUC__) && defined(_ARCH_PPC) && defined(_AIX)
 #include "platform/switch_ppc_aix.h" /* gcc on AIX/PowerPC */
+#elif defined(__GNUC__) && defined(__powerpc__) && defined(__NetBSD__)
+#include "platform/switch_ppc_unix.h" /* gcc on NetBSD/powerpc */
 #elif defined(__GNUC__) && defined(sparc)
 #include "platform/switch_sparc_sun_gcc.h" /* SunOS sparc with gcc */
 #elif defined(__SUNPRO_C) && defined(sparc) && defined(sun)
