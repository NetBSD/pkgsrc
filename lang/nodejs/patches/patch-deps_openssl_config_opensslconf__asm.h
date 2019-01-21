$NetBSD: patch-deps_openssl_config_opensslconf__asm.h,v 1.3 2019/01/21 11:00:45 ryoon Exp $

Add support for NetBSD.

--- deps/openssl/config/opensslconf_asm.h.orig	2018-12-26 05:26:13.000000000 +0000
+++ deps/openssl/config/opensslconf_asm.h
@@ -96,7 +96,7 @@
 # include "./archs/linux-x32/asm/include/openssl/opensslconf.h"
 #elif defined(OPENSSL_LINUX) && defined(__x86_64__)
 # include "./archs/linux-x86_64/asm/include/openssl/opensslconf.h"
-#elif defined(OPENSSL_LINUX) && defined(__arm__)
+#elif (defined(OPENSSL_LINUX) || defined(__NetBSD__)) && defined(__arm__)
 # include "./archs/linux-armv4/asm/include/openssl/opensslconf.h"
 #elif defined(OPENSSL_LINUX) && defined(__aarch64__)
 # include "./archs/linux-aarch64/asm/include/openssl/opensslconf.h"
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
