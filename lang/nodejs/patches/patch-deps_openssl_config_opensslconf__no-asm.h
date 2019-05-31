$NetBSD: patch-deps_openssl_config_opensslconf__no-asm.h,v 1.4 2019/05/31 20:52:00 adam Exp $

Support NetBSD/arm,aarch64,i386,amd64 (and hopefully other ILP32 archs)

--- deps/openssl/config/opensslconf_no-asm.h.orig	2019-05-28 21:32:16.000000000 +0000
+++ deps/openssl/config/opensslconf_no-asm.h
@@ -4,9 +4,9 @@
 # include "./archs/linux-x32/no-asm/include/openssl/opensslconf.h"
 #elif defined(OPENSSL_LINUX) && defined(__x86_64__)
 # include "./archs/linux-x86_64/no-asm/include/openssl/opensslconf.h"
-#elif defined(OPENSSL_LINUX) && defined(__arm__)
+#elif (defined(OPENSSL_LINUX) || defined(__NetBSD__)) && defined(__arm__)
 # include "./archs/linux-armv4/no-asm/include/openssl/opensslconf.h"
-#elif defined(OPENSSL_LINUX) && defined(__aarch64__)
+#elif (defined(OPENSSL_LINUX) || defined(__NetBSD__)) && defined(__aarch64__)
 # include "./archs/linux-aarch64/no-asm/include/openssl/opensslconf.h"
 #elif defined(__APPLE__) && defined(__MACH__) && defined(__i386__)
 # include "./archs/darwin-i386-cc/no-asm/include/openssl/opensslconf.h"
@@ -18,9 +18,9 @@
 # include "./archs/VC-WIN64A/no-asm/include/openssl/opensslconf.h"
 #elif defined(_WIN32) && defined(_M_ARM64)
 # include "./archs/VC-WIN64-ARM/no-asm/include/openssl/opensslconf.h"
-#elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__i386__)
+#elif (defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)) && defined(__i386__)
 # include "./archs/BSD-x86/no-asm/include/openssl/opensslconf.h"
-#elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__x86_64__)
+#elif (defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)) && defined(__x86_64__)
 # include "./archs/BSD-x86_64/no-asm/include/openssl/opensslconf.h"
 #elif defined(__sun) && defined(__i386__)
 # include "./archs/solaris-x86-gcc/no-asm/include/openssl/opensslconf.h"
