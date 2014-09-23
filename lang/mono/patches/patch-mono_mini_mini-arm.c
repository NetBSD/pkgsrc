$NetBSD: patch-mono_mini_mini-arm.c,v 1.3 2014/09/23 22:26:24 jmcneill Exp $

--- mono/mini/mini-arm.c.orig	2014-08-12 16:50:38.000000000 +0000
+++ mono/mini/mini-arm.c
@@ -53,6 +53,11 @@
 #define IS_VFP (TRUE)
 #endif
 
+#ifdef __NetBSD__
+#include <machine/sysarch.h>
+#include <sys/sysctl.h>
+#endif
+
 #if defined(__ARM_EABI__) && defined(__linux__) && !defined(PLATFORM_ANDROID) && !defined(__native_client__)
 #define HAVE_AEABI_READ_TP 1
 #endif
@@ -891,6 +896,10 @@ void
 mono_arch_init (void)
 {
 	const char *cpu_arch;
+#if defined(__NetBSD__)
+	char *s = NULL;
+	size_t len;
+#endif
 
 	InitializeCriticalSection (&mini_arch_mutex);
 #ifdef MONO_ARCH_SOFT_DEBUG_SUPPORTED
@@ -942,6 +951,32 @@ mono_arch_init (void)
 	   have a way to properly detect CPU features on it. */
 	thumb_supported = TRUE;
 	iphone_abi = TRUE;
+#elif defined(__NetBSD__)
+	if (sysctlbyname("machdep.cpu_arch", NULL, &len, NULL, 0) < 0) {
+		/* sysctlbyname error */
+		return;
+	}
+	s = malloc(len);
+	if (sysctlbyname("machdep.cpu_arch", s, &len, NULL, 0) < 0) {
+		/* sysctlbyname error */
+		free(s);
+		return;
+	}
+
+	switch (s[0]) {
+	case '7':
+		v7_supported = TRUE;
+		/* FALLTHROUGH */
+	case '6':
+		v6_supported = TRUE;
+		/* FALLTHROUGH */
+	case '5':
+		v5_supported = TRUE;
+		break;
+	}
+
+	free(s);
+	
 #else
 	thumb_supported = mono_hwcap_arm_has_thumb;
 	thumb2_supported = mono_hwcap_arm_has_thumb2;
@@ -1154,6 +1189,11 @@ mono_arch_flush_icache (guint8 *code, gi
 #ifdef MONO_CROSS_COMPILE
 #elif __APPLE__
 	sys_icache_invalidate (code, size);
+#elif defined(__NetBSD__)
+	struct arm_sync_icache_args args;
+	args.addr = (uintptr_t)code;
+	args.len = (size_t)size;
+	sysarch(ARM_SYNC_ICACHE, &args);
 #elif __GNUC_PREREQ(4, 1)
 	__clear_cache (code, code + size);
 #elif defined(PLATFORM_ANDROID)
