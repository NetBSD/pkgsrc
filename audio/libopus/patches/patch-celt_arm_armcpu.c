$NetBSD: patch-celt_arm_armcpu.c,v 1.3 2024/03/07 17:26:28 adam Exp $

Don't error on ARM if we're not on Darwin, Linux, or MSVC.
Currently the code attempts to open /proc/cpuinfo, and tests for
failure - if that doesn't contain useful info or doesn't exist,
it still behaves correctly.

--- celt/arm/armcpu.c.orig	2024-03-01 07:55:09.000000000 +0000
+++ celt/arm/armcpu.c
@@ -92,7 +92,7 @@ static OPUS_INLINE opus_uint32 opus_cpu_
   return flags;
 }
 
-#elif defined(__linux__)
+#elif !defined(__APPLE__)
 /* Linux based */
 #include <stdio.h>
 
@@ -195,7 +195,7 @@ opus_uint32 opus_cpu_capabilities(void)
 /* The feature registers which can tell us what the processor supports are
  * accessible in priveleged modes only, so we can't have a general user-space
  * detection method like on x86.*/
-# error "Configured to use ARM asm but no CPU detection method available for " \
+# warning "Configured to use ARM asm but no CPU detection method available for " \
    "your platform.  Reconfigure with --disable-rtcd (or send patches)."
 #endif
 
