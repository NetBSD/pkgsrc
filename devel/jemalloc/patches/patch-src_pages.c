$NetBSD: patch-src_pages.c,v 1.4 2019/03/22 15:55:17 schmonz Exp $

Set os_overcommits to true on NetBSD < 8.0 as a workaround for
the issue reported in kern/52239 and
https://github.com/jemalloc/jemalloc/issues/837 .

--- src/pages.c.orig	2018-05-08 19:15:01.000000000 +0000
+++ src/pages.c
@@ -582,6 +582,10 @@ pages_boot(void) {
 		mmap_flags |= MAP_NORESERVE;
 	}
 #  endif
+#elif defined(__NetBSD__)
+#  if !__NetBSD_Prereq__(8,0,0)
+	os_overcommits = true;
+#  endif
 #else
 	os_overcommits = false;
 #endif
