$NetBSD: patch-src_emu_emualloc.h,v 1.1 2013/12/18 17:55:15 joerg Exp $

--- src/emu/emualloc.h.orig	2013-12-18 13:39:10.000000000 +0000
+++ src/emu/emualloc.h
@@ -77,6 +77,7 @@ void dump_unfreed_mem();
 // zeromem_t is a dummy class used to tell new to zero memory after allocation
 class zeromem_t { };
 
+#if 0
 #ifndef NO_MEM_TRACKING
 
 // standard new/delete operators (try to avoid using)
@@ -109,6 +110,7 @@ ATTR_FORCE_INLINE inline void operator d
 }
 
 #endif
+#endif
 
 // file/line new/delete operators
 ATTR_FORCE_INLINE inline void *operator new(std::size_t size, const char *file, int line) throw (std::bad_alloc)
