$NetBSD: patch-src_memseg.cc,v 1.1 2026/01/03 22:28:03 wiz Exp $

Fix mmap() comparison argument.

--- src/memseg.cc.orig	2026-01-03 22:25:08.257865309 +0000
+++ src/memseg.cc
@@ -158,7 +158,7 @@ PrVoidError MemorySegment::map_file(cons
 #if HAVE_MMAP
 PrVoidError MemorySegment::init_mapped_segment()
 {
-    if((_mapped_segment = (caddr_t)mmap(0, _length, PROT_READ, MAP_PRIVATE, _fd, 0)) < 0)
+    if((_mapped_segment = (caddr_t)mmap(0, _length, PROT_READ, MAP_PRIVATE, _fd, 0)) == MAP_FAILED)
 	pthrow prcserror << "Mmap " << squote (_desc) << " failed" << perror;
 
     _segment = _mapped_segment;
