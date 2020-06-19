$NetBSD: patch-mksquashfs.c,v 1.2 2020/06/19 21:17:46 scole Exp $

#ifdef linux includes and don't use sysinfo() unless for linux

--- mksquashfs.c.orig	2019-08-29 01:58:04.000000000 +0000
+++ mksquashfs.c
@@ -35,7 +35,9 @@
 #include <stddef.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#if defined(__linux__)
 #include <sys/sysmacros.h>
+#endif
 #include <fcntl.h>
 #include <errno.h>
 #include <dirent.h>
@@ -50,7 +52,9 @@
 #include <sys/wait.h>
 #include <limits.h>
 #include <ctype.h>
+#if defined(__linux__)
 #include <sys/sysinfo.h>
+#endif
 
 #ifndef linux
 #define __BYTE_ORDER BYTE_ORDER
@@ -5196,6 +5200,7 @@ int get_physical_memory()
 	int phys_mem;
 
 	if(num_pages == -1 || page_size == -1) {
+#if defined(__linux__)
 		struct sysinfo sys;
 		int res = sysinfo(&sys);
 
@@ -5204,6 +5209,9 @@ int get_physical_memory()
 
 		num_pages = sys.totalram;
 		page_size = sys.mem_unit;
+#else
+		BAD_ERROR("Mksquashfs sysconf num_pages or page_size failed!\n");
+#endif
 	}
 
 	phys_mem = num_pages * page_size >> 20;
