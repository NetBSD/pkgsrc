$NetBSD: patch-src_Kernel_Types_tree.hpp,v 1.1 2013/08/13 10:21:35 joerg Exp $

--- src/Kernel/Types/tree.hpp.orig	2013-08-12 16:26:56.000000000 +0000
+++ src/Kernel/Types/tree.hpp
@@ -74,7 +74,7 @@ public:
   friend tree& operator << (tree& t, array<tree> a);
   friend ostream& operator << (ostream& out, tree t);
   friend tree operator * (tree t1, tree t2);
-  friend void print_tree (tree t, int tab=0);
+  friend void print_tree (tree t, int tab);
   friend list<tree> as_trees (list<pointer> l);
   friend class tree_pointer_rep;
   friend class tree_position_rep;
