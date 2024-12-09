$NetBSD: patch-src_as-system-info.c,v 1.5 2024/12/09 11:37:31 adam Exp $

Provide a reasonable fallback for retrieving total memory.

--- src/as-system-info.c.orig	2024-12-08 22:34:32.000000000 +0000
+++ src/as-system-info.c
@@ -520,7 +520,7 @@ as_get_physical_memory_total (void)
 		return (physpages * pagesize) / MB_IN_BYTES;
 	return 0;
 #else
-#error "Implementation of as_get_physical_memory_total() missing for this OS."
+	return sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGESIZE);
 #endif
 }
 
