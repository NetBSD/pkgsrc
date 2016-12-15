$NetBSD: patch-hotspot_src_share_vm_classfile_symbolTable.cpp,v 1.1 2016/12/15 23:56:53 joerg Exp $

Static member variables of templates must be defined. C++11 inline
definitions would be an alternative.

--- hotspot/src/share/vm/classfile/symbolTable.cpp.orig	2016-12-10 16:08:22.000287424 +0000
+++ hotspot/src/share/vm/classfile/symbolTable.cpp
@@ -42,6 +42,8 @@
 
 PRAGMA_FORMAT_MUTE_WARNINGS_FOR_GCC
 
+template <class T, MEMFLAGS F> juint RehashableHashtable<T, F>::_seed = 0;
+
 // --------------------------------------------------------------------------
 
 // the number of buckets a thread claims
