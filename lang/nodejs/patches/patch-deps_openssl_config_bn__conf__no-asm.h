$NetBSD: patch-deps_openssl_config_bn__conf__no-asm.h,v 1.2 2019/05/31 20:52:00 adam Exp $

Support NetBSD/arm,aarch64,i386,amd64 (and hopefully other ILP32 archs)

--- deps/openssl/config/bn_conf_no-asm.h.orig	2019-05-28 21:32:16.000000000 +0000
+++ deps/openssl/config/bn_conf_no-asm.h
@@ -9,9 +9,9 @@
 # include "./archs/linux-x32/no-asm/crypto/include/internal/bn_conf.h"
 #elif defined(OPENSSL_LINUX) && defined(__x86_64__)
 # include "./archs/linux-x86_64/no-asm/crypto/include/internal/bn_conf.h"
-#elif defined(OPENSSL_LINUX) && defined(__arm__)
+#elif (defined(OPENSSL_LINUX) || defined(__NetBSD__)) && defined(__arm__)
 # include "./archs/linux-armv4/no-asm/crypto/include/internal/bn_conf.h"
-#elif defined(OPENSSL_LINUX) && defined(__aarch64__)
+#elif (defined(OPENSSL_LINUX) || defined(__NetBSD__)) && defined(__aarch64__)
 # include "./archs/linux-aarch64/no-asm/crypto/include/internal/bn_conf.h"
 #elif defined(__APPLE__) && defined(__MACH__) && defined(__i386__)
 # include "./archs/darwin-i386-cc/no-asm/crypto/include/internal/bn_conf.h"
@@ -23,9 +23,9 @@
 # include "./archs/VC-WIN64A/no-asm/crypto/include/internal/bn_conf.h"
 #elif defined(_WIN32) && defined(_M_ARM64)
 # include "./archs/VC-WIN64-ARM/no-asm/crypto/include/internal/bn_conf.h"
-#elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__i386__)
+#elif (defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)) && defined(__i386__)
 # include "./archs/BSD-x86/no-asm/crypto/include/internal/bn_conf.h"
-#elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__x86_64__)
+#elif (defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)) && defined(__x86_64__)
 # include "./archs/BSD-x86_64/no-asm/crypto/include/internal/bn_conf.h"
 #elif defined(__sun) && defined(__i386__)
 # include "./archs/solaris-x86-gcc/no-asm/crypto/include/internal/bn_conf.h"
