$NetBSD: patch-libglusterfs_src_common-utils.c,v 1.3 2020/03/23 23:01:48 gdt Exp $

Make NetBSD memory size reading routine 64-bit aware

--- libglusterfs/src/common-utils.c.orig	2018-04-12 17:46:46.578237383 +0000
+++ libglusterfs/src/common-utils.c
@@ -2971,13 +2971,23 @@ get_mem_size ()
 	memsize = page_size * num_pages;
 #endif
 
-#if defined GF_BSD_HOST_OS || defined GF_DARWIN_HOST_OS
+#if defined GF_DARWIN_HOST_OS
 
 	size_t len = sizeof(memsize);
 	int name [] = { CTL_HW, HW_PHYSMEM };
 
 	sysctl (name, 2, &memsize, &len, NULL, 0);
 #endif
+
+#if defined __NetBSD__
+
+	size_t len = sizeof(memsize);
+	int name64 [] = { CTL_HW, HW_PHYSMEM64 };
+
+	sysctl (name64, 2, &memsize, &len, NULL, 0);
+	if (memsize == -1)
+		sysctl (name64, 2, &memsize, &len, NULL, 0);
+#endif
 	return memsize;
 }
 
