$NetBSD: patch-core_SolverTypes.h,v 1.1 2013/11/08 21:15:02 joerg Exp $

--- core/SolverTypes.h.orig	2013-11-08 20:45:57.000000000 +0000
+++ core/SolverTypes.h
@@ -42,18 +42,18 @@ namespace Minisat {
 typedef int Var;
 #define var_Undef (-1)
 
-
 struct Lit {
     int     x;
 
     // Use this as a constructor:
-    friend Lit mkLit(Var var, bool sign = false);
+    friend Lit mkLit(Var var, bool sign);
 
     bool operator == (Lit p) const { return x == p.x; }
     bool operator != (Lit p) const { return x != p.x; }
     bool operator <  (Lit p) const { return x < p.x;  } // '<' makes p, ~p adjacent in the ordering.
 };
 
+Lit mkLit(Var var, bool sign = false);
 
 inline  Lit  mkLit     (Var var, bool sign) { Lit p; p.x = var + var + (int)sign; return p; }
 inline  Lit  operator ~(Lit p)              { Lit q; q.x = p.x ^ 1; return q; }
