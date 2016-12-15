$NetBSD: patch-hotspot_src_share_vm_memory_metaspace.cpp,v 1.1 2016/12/15 23:56:53 joerg Exp $

Static member variables of templates must be defined. C++11 inline
definitions would be an alternative.

--- hotspot/src/share/vm/memory/metaspace.cpp.orig	2016-12-10 16:06:04.248447262 +0000
+++ hotspot/src/share/vm/memory/metaspace.cpp
@@ -50,6 +50,9 @@
 
 PRAGMA_FORMAT_MUTE_WARNINGS_FOR_GCC
 
+template <class Chunk_t, class FreeList_t>
+size_t TreeChunk<Chunk_t, FreeList_t>::_min_tree_chunk_size = sizeof(TreeChunk<Chunk_t,  FreeList_t>)/HeapWordSize;
+
 typedef BinaryTreeDictionary<Metablock, FreeList<Metablock> > BlockTreeDictionary;
 typedef BinaryTreeDictionary<Metachunk, FreeList<Metachunk> > ChunkTreeDictionary;
 
