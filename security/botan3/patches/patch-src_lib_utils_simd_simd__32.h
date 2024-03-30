$NetBSD: patch-src_lib_utils_simd_simd__32.h,v 1.1 2024/03/30 12:40:21 he Exp $

Avoid VSX operations on 32-bit ppc, even if we have altivec.
Ref. https://github.com/randombit/botan/issues/3958

--- src/lib/utils/simd/simd_32.h.orig	2024-02-20 17:28:54.000000000 +0000
+++ src/lib/utils/simd/simd_32.h
@@ -21,6 +21,9 @@
    #undef vector
    #undef bool
    #define BOTAN_SIMD_USE_ALTIVEC
+#ifdef __VSX__
+   #define BOTAN_SIMD_USE_VSX
+#endif
 
 #elif defined(BOTAN_TARGET_SUPPORTS_NEON)
    #include <botan/internal/cpuid.h>
@@ -480,7 +483,15 @@ class SIMD_4x32 final {
          return SIMD_4x32(_mm_or_si128(_mm_srli_epi16(T, 8), _mm_slli_epi16(T, 8)));
 
 #elif defined(BOTAN_SIMD_USE_ALTIVEC)
+#ifdef BOTAN_SIMD_USE_VSX
          return SIMD_4x32(vec_revb(m_simd));
+#else
+	const __vector unsigned char rev[1] = {
+	   { 3,2,1,0, 7,6,5,4, 11,10,9,8, 15,14,13,12 },
+	};
+
+	 return SIMD_4x32(vec_perm(m_simd, m_simd, rev[0]));
+#endif
 
 #elif defined(BOTAN_SIMD_USE_NEON)
          return SIMD_4x32(vreinterpretq_u32_u8(vrev32q_u8(vreinterpretq_u8_u32(m_simd))));
