$NetBSD: patch-src_pages.c,v 1.2 2017/08/27 12:12:25 adam Exp $

Set os_overcommits to true on NetBSD since NetBSD does overcommit.
This also has the benefit of not triggering the issue reported in
https://github.com/jemalloc/jemalloc/issues/837 .

--- src/pages.c.orig	2017-07-02 00:44:25.000000000 +0000
+++ src/pages.c
@@ -414,6 +414,8 @@ pages_boot(void) {
 		mmap_flags |= MAP_NORESERVE;
 	}
 #  endif
+#elif defined __NetBSD__
+	os_overcommits = true;
 #else
 	os_overcommits = false;
 #endif
