$NetBSD: patch-packages_swi-minisat2_C_Solver.C,v 1.1 2012/06/15 18:53:30 joerg Exp $

See SolverType.h.

--- packages/swi-minisat2/C/Solver.C.orig	2012-06-15 18:36:17.000000000 +0000
+++ packages/swi-minisat2/C/Solver.C
@@ -26,6 +26,14 @@ OF OR IN CONNECTION WITH THE SOFTWARE OR
 //=================================================================================================
 // Constructor/Destructor:
 
+template<class V> Clause* Clause_new(const V& ps, bool learnt)
+{
+  assert(sizeof(Lit)      == sizeof(uint32_t));
+  assert(sizeof(float)    == sizeof(uint32_t));
+  void* mem = malloc(sizeof(Clause) + sizeof(uint32_t)*(ps.size()));
+  return new (mem) Clause(ps, learnt);
+}
+
 
 Solver::Solver() :
 
