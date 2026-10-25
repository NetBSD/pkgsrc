$NetBSD: patch-deps_v8_src_compiler_turboshaft_int64-lowering-reducer.h,v 1.1.2.2 2026/10/25 09:16:51 bsiegert Exp $

* Fix build under NetBSD/i386.

--- deps/v8/src/compiler/turboshaft/int64-lowering-reducer.h.orig	2026-09-08 00:10:00.000000000 +0000
+++ deps/v8/src/compiler/turboshaft/int64-lowering-reducer.h
@@ -637,7 +637,7 @@ class Int64LoweringReducer : public Next {
       result = __ Word32CountLeadingZeros(high);
     }
 
-    return __ Tuple<Word32, Word32>(result, __ Word32Constant(0));
+    return __ template Tuple<Word32, Word32>(result, __ Word32Constant(0));
   }
 
   V<Word32Pair> LowerCtz(V<Word32Pair> input) {
@@ -650,7 +650,7 @@ class Int64LoweringReducer : public Next {
       result = __ Word32CountTrailingZeros(low);
     }
 
-    return __ Tuple<Word32, Word32>(result, __ Word32Constant(0));
+    return __ template Tuple<Word32, Word32>(result, __ Word32Constant(0));
   }
 
   V<Word32Pair> LowerPopCount(V<Word32Pair> input) {
