$NetBSD: patch-src_pages.c,v 1.3 2019/03/17 13:28:22 rin Exp $

Set os_overcommits to true on NetBSD < 8.0 as a workaround for
the issue reported in kern/52239 and
https://github.com/jemalloc/jemalloc/issues/837 .

--- src/pages.c.orig	2018-05-09 04:15:01.000000000 +0900
+++ src/pages.c	2019-03-17 22:02:09.325743870 +0900
@@ -582,6 +582,8 @@ pages_boot(void) {
 		mmap_flags |= MAP_NORESERVE;
 	}
 #  endif
+#elif defined(__NetBSD__) && !__NetBSD_Prereq__(8,0,0)
+	os_overcommits = true;
 #else
 	os_overcommits = false;
 #endif
