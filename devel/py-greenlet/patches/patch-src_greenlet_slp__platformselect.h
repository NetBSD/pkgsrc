$NetBSD: patch-src_greenlet_slp__platformselect.h,v 1.6 2025/05/22 09:24:30 nia Exp $

Add support for NetBSD/sparc[64] (and other sparc operating systems).

--- src/greenlet/slp_platformselect.h.orig	2025-04-11 18:34:32.000000000 +0000
+++ src/greenlet/slp_platformselect.h
@@ -31,6 +31,8 @@ extern "C" {
 #include "platform/switch_ppc_unix.h" /* gcc on NetBSD/powerpc */
 #elif defined(__GNUC__) && defined(sparc)
 # include "platform/switch_sparc_sun_gcc.h" /* SunOS sparc with gcc */
+#elif defined(__GNUC__) && defined(__sparc__)
+# include "platform/switch_sparc_sun_gcc.h" /* SunOS sparc with gcc */
 #elif defined(__SUNPRO_C) && defined(sparc) && defined(sun)
 # include "platform/switch_sparc_sun_gcc.h" /* SunStudio on amd64 */
 #elif defined(__SUNPRO_C) && defined(__amd64__) && defined(sun)
