$NetBSD: patch-celt_arm_armcpu.c,v 1.4 2025/12/20 22:21:28 wiz Exp $

Don't error on ARM if we're not on Darwin, Linux, or MSVC.
Currently the code attempts to open /proc/cpuinfo, and tests for
failure - if that doesn't contain useful info or doesn't exist,
it still behaves correctly.

--- celt/arm/armcpu.c.orig	2025-11-07 22:12:41.000000000 +0000
+++ celt/arm/armcpu.c
@@ -92,7 +92,7 @@ static OPUS_INLINE opus_uint32 opus_cpu_
   return flags;
 }
 
-#elif defined(__linux__)
+#elif !defined(__APPLE__)
 /* Linux based */
 #include <stdio.h>
 
@@ -275,7 +275,7 @@ static opus_uint32 opus_cpu_capabilities
 /* The feature registers which can tell us what the processor supports are
  * accessible in privileged modes only, so we can't have a general user-space
  * detection method like on x86.*/
-# error "Configured to use ARM asm but no CPU detection method available for " \
+# warning "Configured to use ARM asm but no CPU detection method available for " \
    "your platform.  Reconfigure with --disable-rtcd (or send patches)."
 #endif
 
