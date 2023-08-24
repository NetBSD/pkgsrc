$NetBSD: patch-src_ext_equix_hashx_src_virtual__memory.c,v 1.1 2023/08/24 18:56:42 wiz Exp $

Compilation fix on NetBSD.
https://gitlab.torproject.org/tpo/core/tor/-/issues/40843

--- src/ext/equix/hashx/src/virtual_memory.c.orig	2023-08-23 14:16:00.000000000 +0000
+++ src/ext/equix/hashx/src/virtual_memory.c
@@ -106,8 +106,8 @@ void* hashx_vm_alloc_huge(size_t bytes) 
 #elif defined(__FreeBSD__)
 	mem = mmap(NULL, bytes, PAGE_READWRITE, MAP_PRIVATE | MAP_ANONYMOUS
 		| MAP_ALIGNED_SUPER, -1, 0);
-#elif defined(__OpenBSD__)
-	mem = MAP_FAILED; // OpenBSD does not support huge pages
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
+	mem = MAP_FAILED; // OpenBSD and NetBSD do not support huge pages
 #else
 	mem = mmap(NULL, bytes, PAGE_READWRITE, MAP_PRIVATE | MAP_ANONYMOUS
 		| MAP_HUGETLB | MAP_POPULATE, -1, 0);
