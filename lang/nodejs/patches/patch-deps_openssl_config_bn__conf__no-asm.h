$NetBSD: patch-deps_openssl_config_bn__conf__no-asm.h,v 1.1 2019/02/24 12:18:55 rin Exp $

Support NetBSD/arm,aarch64,i386,amd64 (and hopefully other ILP32 archs)

--- deps/openssl/config/bn_conf_no-asm.h.orig	2019-01-29 16:20:45.000000000 +0900
+++ deps/openssl/config/bn_conf_no-asm.h	2019-02-24 10:23:06.960730222 +0900
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
@@ -21,9 +21,10 @@
 # include "./archs/VC-WIN32/no-asm/crypto/include/internal/bn_conf.h"
 #elif defined(_WIN32) && defined(_M_X64)
 # include "./archs/VC-WIN64A/no-asm/crypto/include/internal/bn_conf.h"
-#elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__i386__)
-# include "./archs/BSD-x86/no-asm/crypto/include/internal/bn_conf.h"
-#elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__x86_64__)
+// XXX missing
+//#elif (defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)) && defined(__i386__)
+//# include "./archs/BSD-x86/no-asm/crypto/include/internal/bn_conf.h"
+#elif (defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)) && defined(__x86_64__)
 # include "./archs/BSD-x86_64/no-asm/crypto/include/internal/bn_conf.h"
 #elif defined(__sun) && defined(__i386__)
 # include "./archs/solaris-x86-gcc/no-asm/crypto/include/internal/bn_conf.h"
