$NetBSD: patch-celt_arm_armcpu.c,v 1.1 2017/05/13 07:51:08 maya Exp $

Don't error on ARM if we're not on linux or MSVC.
Currently the code attempts to open /proc/cpuinfo, and tests for
failure - if that doesn't contain useful info or doesn't exist,
it still behaves correctly.

--- celt/arm/armcpu.c.orig	2017-01-16 20:50:20.000000000 +0000
+++ celt/arm/armcpu.c
@@ -91,7 +91,7 @@ static OPUS_INLINE opus_uint32 opus_cpu_
   return flags;
 }
 
-#elif defined(__linux__)
+#else
 /* Linux based */
 opus_uint32 opus_cpu_capabilities(void)
 {
@@ -146,11 +146,12 @@ opus_uint32 opus_cpu_capabilities(void)
   }
   return flags;
 }
-#else
+#endif
+#if !(defined(__linux__) || defined(_MSC_VER))
 /* The feature registers which can tell us what the processor supports are
  * accessible in priveleged modes only, so we can't have a general user-space
  * detection method like on x86.*/
-# error "Configured to use ARM asm but no CPU detection method available for " \
+# warning "Configured to use ARM asm but no CPU detection method available for " \
    "your platform.  Reconfigure with --disable-rtcd (or send patches)."
 #endif
 
