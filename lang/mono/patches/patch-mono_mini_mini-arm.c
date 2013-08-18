$NetBSD: patch-mono_mini_mini-arm.c,v 1.1 2013/08/18 09:42:31 jmcneill Exp $

--- mono/mini/mini-arm.c.orig	2013-04-25 09:01:55.000000000 +0000
+++ mono/mini/mini-arm.c
@@ -25,6 +25,11 @@
 #include "mono/arch/arm/arm-fpa-codegen.h"
 #include "mono/arch/arm/arm-vfp-codegen.h"
 
+#ifdef __NetBSD__
+#include <machine/sysarch.h>
+#include <sys/sysctl.h>
+#endif
+
 #if defined(__ARM_EABI__) && defined(__linux__) && !defined(PLATFORM_ANDROID) && !defined(__native_client__)
 #define HAVE_AEABI_READ_TP 1
 #endif
@@ -845,6 +850,34 @@ mono_arch_cpu_optimizations (guint32 *ex
 	v5_supported = TRUE;
 	darwin = TRUE;
 	iphone_abi = TRUE;
+#elif defined(__NetBSD__)
+	char *s = NULL;
+	size_t len;
+	if (sysctlbyname("machdep.cpu_arch", NULL, &len, NULL, 0) < 0) {
+		/* sysctlbyname error */
+		return opts;
+	}
+	s = malloc(len);
+	if (sysctlbyname("machdep.cpu_arch", s, &len, NULL, 0) < 0) {
+		/* sysctlbyname error */
+		free(s);
+		return opts;
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
 	char buf [512];
 	char *line;
@@ -1022,6 +1055,11 @@ mono_arch_flush_icache (guint8 *code, gi
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
