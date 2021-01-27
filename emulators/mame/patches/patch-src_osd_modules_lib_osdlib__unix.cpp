$NetBSD: patch-src_osd_modules_lib_osdlib__unix.cpp,v 1.1 2021/01/27 17:06:06 wiz Exp $

Prepare mmap'd page for later mprotect().
https://github.com/mamedev/mame/issues/7712

--- src/osd/modules/lib/osdlib_unix.cpp.orig	2021-01-26 04:43:24.000000000 +0000
+++ src/osd/modules/lib/osdlib_unix.cpp
@@ -189,7 +189,11 @@ void *virtual_memory_allocation::do_allo
 	// TODO: portable applications are supposed to use -1 for anonymous mappings - detect whatever requires 0 specifically
 	int const fd(0);
 #endif
+#ifdef __NetBSD__
+	void *const result(mmap(nullptr, s, PROT_MPROTECT(PROT_EXEC|PROT_WRITE|PROT_READ), MAP_ANON | MAP_SHARED, fd, 0));
+#else
 	void *const result(mmap(nullptr, s, PROT_NONE, MAP_ANON | MAP_SHARED, fd, 0));
+#endif
 	if (result == (void *)-1)
 		return nullptr;
 	size = s;
