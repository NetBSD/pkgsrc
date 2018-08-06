$NetBSD: patch-libglusterfs_src_common-utils.c,v 1.2 2018/08/06 02:22:31 manu Exp $

Make NetBSD memory size reading routine 64-bit aware

--- libglusterfs/src/common-utils.c.orig	2018-08-05 19:00:57.102350607 +0200
+++ libglusterfs/src/common-utils.c	2018-08-05 19:21:38.677872008 +0200
@@ -2970,15 +2970,25 @@
 
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
 
 /* Strips all whitespace characters in a string and returns length of new string
