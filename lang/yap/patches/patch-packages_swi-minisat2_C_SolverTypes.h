$NetBSD: patch-packages_swi-minisat2_C_SolverTypes.h,v 1.4 2015/12/29 23:34:57 dholland Exp $

Fix C++ dialect.

--- packages/swi-minisat2/C/SolverTypes.h.orig	2012-06-29 21:19:52.000000000 +0000
+++ packages/swi-minisat2/C/SolverTypes.h
@@ -119,7 +119,7 @@ public:
 
     // -- use this function instead:
     template<class V>
-    friend Clause* Clause_new(const V& ps, bool learnt = false);
+    friend Clause* Clause_new(const V& ps, bool learnt);
 
     int          size        ()      const   { return size_etc >> 3; }
     void         shrink      (int i)         { assert(i <= size()); size_etc = (((size_etc >> 3) - i) << 3) | (size_etc & 7); }
