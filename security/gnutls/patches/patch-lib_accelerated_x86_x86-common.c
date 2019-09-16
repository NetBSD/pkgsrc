$NetBSD: patch-lib_accelerated_x86_x86-common.c,v 1.3 2019/09/16 17:01:46 nros Exp $

Fix compilation on gcc and clang versions missing __get_cpuid_count.
taken from upstream:
https://gitlab.com/gnutls/gnutls/commit/ef80617d1e17e0878a909baad62a75ba265c0e00
This is fixed in 3.6.10 so remove the things related to cpuid 
when updating to 3.6.10 or above.

Avoid unsupported xgetbv instruction on older Darwin assemblers.

--- lib/accelerated/x86/x86-common.c.orig	2019-06-28 19:06:07.000000000 +0000
+++ lib/accelerated/x86/x86-common.c
@@ -106,17 +106,33 @@ unsigned int _gnutls_x86_cpuid_s[4];
 #define VIA_PADLOCK_PHE (1<<21)
 #define VIA_PADLOCK_PHE_SHA512 (1<<22)
 
+#ifndef HAVE_GET_CPUID_COUNT
+static inline void
+get_cpuid_level7(unsigned int *eax, unsigned int *ebx,
+                unsigned int *ecx, unsigned int *edx)
+{
+       /* we avoid using __get_cpuid_count, because it is not available with gcc 4.8 */
+       if (__get_cpuid_max(7, 0) < 7)
+               return;
+
+       __cpuid_count(7, 0, *eax, *ebx, *ecx, *edx);
+       return;
+}
+#else
+# define get_cpuid_level7(a,b,c,d) __get_cpuid_count(7, 0, a, b, c, d)
+#endif
+
 static unsigned read_cpuid_vals(unsigned int vals[4])
 {
 	unsigned t1, t2, t3;
-	if (!__get_cpuid(1, &t1, &vals[0],
-			 &vals[1], &t2))
+        vals[0] = vals[1] = vals[2] = vals[3] = 0;
+
+        if (!__get_cpuid(1, &t1, &vals[0], &vals[1], &t2))
 		return 0;
 	/* suppress AVX512; it works conditionally on certain CPUs on the original code */
 	vals[1] &= 0xfffff7ff;
 
-	if (!__get_cpuid_count(7, 0, &t1, &vals[2], &t2, &t3))
-		return 0;
+        get_cpuid_level7(&t1, &vals[2], &t2, &t3);
 
 	return 1;
 }
@@ -134,6 +150,8 @@ static unsigned check_4th_gen_intel_feat
 
 #if defined(_MSC_VER) && !defined(__clang__)
 	xcr0 = _xgetbv(0);
+#elif defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ < 1070
+	return 0;
 #else
 	__asm__ ("xgetbv" : "=a" (xcr0) : "c" (0) : "%edx");
 #endif
