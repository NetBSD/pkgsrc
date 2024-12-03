$NetBSD: patch-src_as-system-info.c,v 1.4 2024/12/03 10:35:55 jperkin Exp $

Provide a reasonable fallback for retrieving total memory.

--- src/as-system-info.c.orig	2024-12-03 10:27:19.242982022 +0000
+++ src/as-system-info.c
@@ -499,7 +499,7 @@ as_get_physical_memory_total (void)
 	GlobalMemoryStatusEx (&statex);
 	return statex.ullTotalPhys / (1024 * 1024);
 #else
-#error "Implementation of as_get_physical_memory_total() missing for this OS."
+	return sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGESIZE);
 #endif
 }
 
