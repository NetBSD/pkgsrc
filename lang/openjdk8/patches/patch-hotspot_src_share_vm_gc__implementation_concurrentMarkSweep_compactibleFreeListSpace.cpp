$NetBSD: patch-hotspot_src_share_vm_gc__implementation_concurrentMarkSweep_compactibleFreeListSpace.cpp,v 1.1 2016/12/15 23:56:53 joerg Exp $

Static member variables of templates must be defined. C++11 inline
definitions would be an alternative.

--- hotspot/src/share/vm/gc_implementation/concurrentMarkSweep/compactibleFreeListSpace.cpp.orig	2016-12-10 16:01:00.232060787 +0000
+++ hotspot/src/share/vm/gc_implementation/concurrentMarkSweep/compactibleFreeListSpace.cpp
@@ -48,6 +48,9 @@
 //// CompactibleFreeListSpace
 /////////////////////////////////////////////////////////////////////////
 
+template <class Chunk_t, class FreeList_t>
+size_t TreeChunk<Chunk_t, FreeList_t>::_min_tree_chunk_size = sizeof(TreeChunk<Chunk_t,  FreeList_t>)/HeapWordSize;
+
 // highest ranked  free list lock rank
 int CompactibleFreeListSpace::_lockRank = Mutex::leaf + 3;
 
