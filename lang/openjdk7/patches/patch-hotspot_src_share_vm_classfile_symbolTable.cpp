$NetBSD: patch-hotspot_src_share_vm_classfile_symbolTable.cpp,v 1.1 2017/09/04 16:00:19 joerg Exp $

Static member variables of templates must be defined. C++11 inline
definitions would be an alternative.

--- hotspot/src/share/vm/classfile/symbolTable.cpp.orig	2017-08-13 05:55:28.000000000 +0000
+++ hotspot/src/share/vm/classfile/symbolTable.cpp
@@ -37,6 +37,9 @@
 #include "utilities/hashtable.inline.hpp"
 #include "utilities/numberSeq.hpp"
 
+template <> jint Hashtable<Symbol *, mtSymbol>::_seed = 0;
+template <> jint Hashtable<oopDesc *, mtSymbol>::_seed = 0;
+
 // --------------------------------------------------------------------------
 
 // the number of buckets a thread claims
