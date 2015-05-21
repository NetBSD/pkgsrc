$NetBSD: patch-mono_mini_mini-arm.c,v 1.5 2015/05/21 14:38:08 kefren Exp $

--- mono/mini/mini-arm.c.orig	2015-04-30 13:27:46.000000000 +0300
+++ mono/mini/mini-arm.c	2015-05-11 15:55:15.000000000 +0300
@@ -56,6 +56,11 @@
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
@@ -922,6 +927,10 @@ void
 mono_arch_init (void)
 {
 	const char *cpu_arch;
+#if defined(__NetBSD__)
+	char *s = NULL;
+	size_t len;
+#endif
 
 	mono_mutex_init_recursive (&mini_arch_mutex);
 #ifdef MONO_ARCH_SOFT_DEBUG_SUPPORTED
@@ -986,6 +995,32 @@ mono_arch_init (void)
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
@@ -1196,6 +1231,11 @@ mono_arch_flush_icache (guint8 *code, gi
 #ifdef MONO_CROSS_COMPILE
 #elif __APPLE__
 	sys_icache_invalidate (code, size);
+#elif defined(__NetBSD__)
+	struct arm_sync_icache_args args;
+	args.addr = (uintptr_t)code;
+	args.len = (size_t)size;
+	sysarch(ARM_SYNC_ICACHE, &args);
 #elif __GNUC_PREREQ(4, 3)
     __builtin___clear_cache (code, code + size);
 #elif __GNUC_PREREQ(4, 1)
