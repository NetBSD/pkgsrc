$NetBSD: patch-performance.c,v 1.1 2015/04/21 17:18:01 joerg Exp $

--- performance.c.orig	2015-04-17 14:36:16.000000000 +0000
+++ performance.c
@@ -306,7 +306,7 @@ static uint64_t xgetbv_x86(uint32_t idx)
 }
 #endif
 
-#if defined(__ARM_NEON__)
+#if defined(HAVE_NEON)
 static void arm_enable_runfast_mode(void)
 {
    /* RunFast mode. Enables flush-to-zero and some 
@@ -464,7 +464,7 @@ uint64_t rarch_get_cpu_features(void)
    uint64_t cpu_flags = android_getCpuFeatures();
    (void)cpu_flags;
 
-#ifdef __ARM_NEON__
+#ifdef HAVE_NEON
    if (cpu_flags & ANDROID_CPU_ARM_FEATURE_NEON)
    {
       cpu |= RETRO_SIMD_NEON;
@@ -472,7 +472,7 @@ uint64_t rarch_get_cpu_features(void)
    }
 #endif
 
-#elif defined(__ARM_NEON__)
+#elif defined(HAVE_NEON)
    cpu |= RETRO_SIMD_NEON;
    arm_enable_runfast_mode();
 #elif defined(__ALTIVEC__)
