$NetBSD: patch-deps_openssl_config_opensslconf__asm.h,v 1.4 2019/02/24 12:18:55 rin Exp $

Support NetBSD/arm,aarch64,i386,amd64 (and hopefully other ILP32 archs)

--- deps/openssl/config/opensslconf_asm.h.orig	2019-01-29 16:20:45.000000000 +0900
+++ deps/openssl/config/opensslconf_asm.h	2019-02-24 09:05:18.803688546 +0900
@@ -96,9 +96,9 @@
 # include "./archs/linux-x32/asm/include/openssl/opensslconf.h"
 #elif defined(OPENSSL_LINUX) && defined(__x86_64__)
 # include "./archs/linux-x86_64/asm/include/openssl/opensslconf.h"
-#elif defined(OPENSSL_LINUX) && defined(__arm__)
+#elif (defined(OPENSSL_LINUX) || defined(__NetBSD__)) && defined(__arm__)
 # include "./archs/linux-armv4/asm/include/openssl/opensslconf.h"
-#elif defined(OPENSSL_LINUX) && defined(__aarch64__)
+#elif (defined(OPENSSL_LINUX) || defined(__NetBSD__)) && defined(__aarch64__)
 # include "./archs/linux-aarch64/asm/include/openssl/opensslconf.h"
 #elif defined(__APPLE__) && defined(__MACH__) && defined(__i386__)
 # include "./archs/darwin-i386-cc/asm/include/openssl/opensslconf.h"
@@ -108,9 +108,7 @@
 # include "./archs/VC-WIN32/asm/include/openssl/opensslconf.h"
 #elif defined(_WIN32) && defined(_M_X64)
 # include "./archs/VC-WIN64A/asm/include/openssl/opensslconf.h"
-#elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__i386__)
-# include "./archs/BSD-x86/asm/include/openssl/opensslconf.h"
-#elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__x86_64__)
+#elif (defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)) && defined(__x86_64__)
 # include "./archs/BSD-x86_64/asm/include/openssl/opensslconf.h"
 #elif defined(__sun) && defined(__i386__)
 # include "./archs/solaris-x86-gcc/asm/include/openssl/opensslconf.h"
