$NetBSD: patch-deps_openssl_config_opensslconf__asm.h,v 1.1 2018/05/03 21:19:16 fhajny Exp $

Add support for NetBSD.

--- deps/openssl/config/opensslconf_asm.h.orig	2018-04-24 14:41:19.000000000 +0000
+++ deps/openssl/config/opensslconf_asm.h
@@ -108,9 +108,9 @@
 # include "./archs/VC-WIN32/asm/include/openssl/opensslconf.h"
 #elif defined(_WIN32) && defined(_M_X64)
 # include "./archs/VC-WIN64A/asm/include/openssl/opensslconf.h"
-#elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__i386__)
+#elif (defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)) && defined(__i386__)
 # include "./archs/BSD-x86/asm/include/openssl/opensslconf.h"
-#elif (defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__x86_64__)
+#elif (defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)) && defined(__x86_64__)
 # include "./archs/BSD-x86_64/asm/include/openssl/opensslconf.h"
 #elif defined(__sun) && defined(__i386__)
 # include "./archs/solaris-x86-gcc/asm/include/openssl/opensslconf.h"
