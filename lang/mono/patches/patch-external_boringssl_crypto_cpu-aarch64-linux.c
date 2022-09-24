$NetBSD: patch-external_boringssl_crypto_cpu-aarch64-linux.c,v 1.1 2022/09/24 07:48:06 nia Exp $

NetBSD does not have sys/auxv.h.

XXX: This needs to be fixed to actually check for AES instructions, etc.
Perhaps there's a machdep sysctl variable?

--- external/boringssl/crypto/cpu-aarch64-linux.c.orig	2021-02-22 15:51:09.000000000 +0000
+++ external/boringssl/crypto/cpu-aarch64-linux.c
@@ -16,8 +16,6 @@
 
 #if defined(OPENSSL_AARCH64) && !defined(OPENSSL_STATIC_ARMCAP)
 
-#include <sys/auxv.h>
-
 #include <openssl/arm_arch.h>
 
 #include "internal.h"
@@ -65,8 +63,15 @@ void OPENSSL_cpuid_setup(void) {
   }
 }
 
+#elif defined(__NetBSD__)
+
+void OPENSSL_cpuid_setup(void) {
+  OPENSSL_armcap_P |= ARMV7_NEON;
+}
 #else // linux
 
+#include <sys/auxv.h>
+
 void OPENSSL_cpuid_setup(void) {
   unsigned long hwcap = getauxval(AT_HWCAP);
 
