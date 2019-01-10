$NetBSD: patch-deps_openssl_config_opensslconf__no-asm.h,v 1.2 2019/01/10 13:02:41 ryoon Exp $

Add support for NetBSD.

--- deps/openssl/config/opensslconf_no-asm.h.orig	2018-12-10 21:19:03.000000000 +0000
+++ deps/openssl/config/opensslconf_no-asm.h
@@ -4,7 +4,7 @@
 # include "./archs/linux-x32/no-asm/include/openssl/opensslconf.h"
 #elif defined(OPENSSL_LINUX) && defined(__x86_64__)
 # include "./archs/linux-x86_64/no-asm/include/openssl/opensslconf.h"
-#elif defined(OPENSSL_LINUX) && defined(__arm__)
+#elif (defined(OPENSSL_LINUX) || defined(__NetBSD__)) && defined(__arm__)
 # include "./archs/linux-armv4/no-asm/include/openssl/opensslconf.h"
 #elif defined(OPENSSL_LINUX) && defined(__aarch64__)
 # include "./archs/linux-aarch64/no-asm/include/openssl/opensslconf.h"
@@ -16,9 +16,9 @@
 # include "./archs/VC-WIN32/no-asm/include/openssl/opensslconf.h"
 #elif defined(_WIN32) && defined(_M_X64)
 # include "./archs/VC-WIN64A/no-asm/include/openssl/opensslconf.h"
-#elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__i386__)
+#elif (defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)) && defined(__i386__)
 # include "./archs/BSD-x86/no-asm/include/openssl/opensslconf.h"
-#elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__x86_64__)
+#elif (defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)) && defined(__x86_64__)
 # include "./archs/BSD-x86_64/no-asm/include/openssl/opensslconf.h"
 #elif defined(__sun) && defined(__i386__)
 # include "./archs/solaris-x86-gcc/no-asm/include/openssl/opensslconf.h"
