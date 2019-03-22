$NetBSD: patch-src_pages.c,v 1.5 2019/03/22 16:30:02 rin Exp $

Set os_overcommits to true on NetBSD < 8.0 as a workaround for
the issue reported in kern/52239 and
https://github.com/jemalloc/jemalloc/issues/837 .

--- src/pages.c.orig	2018-05-09 04:15:01.000000000 +0900
+++ src/pages.c	2019-03-23 01:24:38.101144076 +0900
@@ -582,6 +582,12 @@ pages_boot(void) {
 		mmap_flags |= MAP_NORESERVE;
 	}
 #  endif
+#elif defined(__NetBSD__)
+#  if !__NetBSD_Prereq__(8,0,0)
+	os_overcommits = true;
+#  else
+	os_overcommits = false;
+#  endif
 #else
 	os_overcommits = false;
 #endif
