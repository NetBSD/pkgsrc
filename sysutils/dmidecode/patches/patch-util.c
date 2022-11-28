$NetBSD: patch-util.c,v 1.1 2022/11/28 04:26:08 mrg Exp $

* Use /dev/smbios instead of /dev/mem on NetBSD if available.

--- util.c.orig	2022-06-27 08:06:32.000000000 -0700
+++ util.c	2022-11-27 14:28:45.657997798 -0800
@@ -36,6 +36,9 @@
 #define MAP_FAILED ((void *) -1)
 #endif /* !MAP_FAILED */
 #endif /* USE MMAP */
+#ifdef __NetBSD__
+#include <sys/sysctl.h>
+#endif
 
 #include <stdio.h>
 #include <stdlib.h>
@@ -314,3 +317,28 @@
 
 	return res;
 }
+
+#ifdef USE_DEFAULT_MEM_DEV_FUNC
+const char *
+default_mem_dev(void)
+{
+#ifdef __NetBSD__
+	uint64_t addr;
+	size_t addrlen = sizeof addr;
+	int ret;
+
+	/*
+	 * If machdep.smbios exists and has a non-zero value, /dev/smbios
+	 * should work.  Otherwise fallback to /dev/mem.
+	 */
+	ret = sysctlbyname("machdep.smbios", &addr, &addrlen, NULL, 0);
+	if (ret == 0 && addr != 0) {
+		return "/dev/smbios";
+	} else {
+		return "/dev/mem";
+	}
+#else
+# error "not implemented."
+#endif
+}
+#endif
