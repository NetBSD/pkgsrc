$NetBSD: patch-packages_swi-minisat2_C_SolverTypes.h,v 1.1 2012/06/15 18:53:30 joerg Exp $

Templated friend must be declared outside class.

--- packages/swi-minisat2/C/SolverTypes.h.orig	2011-06-11 15:38:37.000000000 +0000
+++ packages/swi-minisat2/C/SolverTypes.h
@@ -119,11 +119,7 @@ public:
 
     // -- use this function instead:
     template<class V>
-    friend Clause* Clause_new(const V& ps, bool learnt = false) {
-        assert(sizeof(Lit)      == sizeof(uint32_t));
-        assert(sizeof(float)    == sizeof(uint32_t));
-        void* mem = malloc(sizeof(Clause) + sizeof(uint32_t)*(ps.size()));
-        return new (mem) Clause(ps, learnt); }
+    friend Clause* Clause_new(const V& ps, bool learnt = false);
 
     int          size        ()      const   { return size_etc >> 3; }
     void         shrink      (int i)         { assert(i <= size()); size_etc = (((size_etc >> 3) - i) << 3) | (size_etc & 7); }
