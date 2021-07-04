$NetBSD: patch-mysys_crc32_crc32__arm64.c,v 1.1.2.2 2021/07/04 19:12:07 bsiegert Exp $

Fix building on NetBSD/aarch64.

--- mysys/crc32/crc32_arm64.c.orig	2021-05-05 21:00:19.000000000 +0000
+++ mysys/crc32/crc32_arm64.c
@@ -2,13 +2,13 @@
 #include <string.h>
 #include <stdint.h>
 
+static int pmull_supported;
+
 #if defined(HAVE_ARMV8_CRC)
 
 #if defined(__APPLE__)
 #include <sys/sysctl.h>
 
-static int pmull_supported;
-
 int crc32_aarch64_available(void)
 {
   int ret;
@@ -48,8 +48,6 @@ static unsigned long getauxval(unsigned 
 # define HWCAP_PMULL (1 << 4)
 #endif
 
-static int pmull_supported;
-
 /* ARM made crc32 default from ARMv8.1 but optional in ARMv8A
  * Runtime check API.
  */
