$NetBSD: patch-src_greenlet_slp__platformselect.h,v 1.4 2024/03/30 20:11:51 wiz Exp $

Add support for NetBSD/powerpc.
https://github.com/python-greenlet/greenlet/pull/402

--- src/greenlet/slp_platformselect.h.orig	2023-12-21 21:57:40.000000000 +0000
+++ src/greenlet/slp_platformselect.h
@@ -27,6 +27,8 @@ extern "C" {
 # include "platform/switch_ppc64_aix.h" /* gcc on AIX/PowerPC 64-bit */
 #elif defined(__GNUC__) && defined(_ARCH_PPC) && defined(_AIX)
 # include "platform/switch_ppc_aix.h" /* gcc on AIX/PowerPC */
+#elif defined(__GNUC__) && defined(__powerpc__) && defined(__NetBSD__)
+#include "platform/switch_ppc_unix.h" /* gcc on NetBSD/powerpc */
 #elif defined(__GNUC__) && defined(sparc)
 # include "platform/switch_sparc_sun_gcc.h" /* SunOS sparc with gcc */
 #elif defined(__SUNPRO_C) && defined(sparc) && defined(sun)
