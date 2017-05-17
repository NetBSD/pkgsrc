$NetBSD: patch-src_pages.c,v 1.1 2017/05/17 16:36:46 gson Exp $

Set os_overcommits to true on NetBSD since NetBSD does overcommit.
This also has the benefit of not triggering the issue reported in
https://github.com/jemalloc/jemalloc/issues/837 .

--- src/pages.c.orig	2017-03-01 03:10:36.000000000 +0000
+++ src/pages.c
@@ -296,6 +296,8 @@ pages_boot(void)
 	if (os_overcommits)
 		mmap_flags |= MAP_NORESERVE;
 #  endif
+#elif defined __NetBSD__
+	os_overcommits = true;
 #else
 	os_overcommits = false;
 #endif
