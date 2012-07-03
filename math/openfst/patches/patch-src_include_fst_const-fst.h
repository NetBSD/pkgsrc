$NetBSD: patch-src_include_fst_const-fst.h,v 1.1 2012/07/03 17:42:05 joerg Exp $

--- src/include/fst/const-fst.h.orig	2012-07-03 09:46:39.000000000 +0000
+++ src/include/fst/const-fst.h
@@ -139,8 +139,8 @@ ConstFstImpl<A, U>::ConstFstImpl(const F
   SetType(type);
   uint64 copy_properties = fst.Properties(kCopyProperties, true);
   SetProperties(copy_properties | kStaticProperties);
-  SetInputSymbols(fst.InputSymbols());
-  SetOutputSymbols(fst.OutputSymbols());
+  this->SetInputSymbols(fst.InputSymbols());
+  this->SetOutputSymbols(fst.OutputSymbols());
   start_ = fst.Start();
 
   // Count # of states and arcs.
