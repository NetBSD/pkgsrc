$NetBSD: patch-lib_accelerated_x86_x86-common.c,v 1.1 2017/04/10 10:43:49 jperkin Exp $

Avoid unsupported xgetbv instruction on older Darwin assemblers.

--- lib/accelerated/x86/x86-common.c.orig	2017-01-22 00:00:30.000000000 +0000
+++ lib/accelerated/x86/x86-common.c
@@ -101,6 +101,8 @@ static unsigned check_4th_gen_intel_feat
 
 #if defined(_MSC_VER)
 	xcr0 = _xgetbv(0);
+#elif defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ < 1070
+	return 0;
 #else
 	__asm__ ("xgetbv" : "=a" (xcr0) : "c" (0) : "%edx");
 #endif
