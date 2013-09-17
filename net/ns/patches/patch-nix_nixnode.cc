$NetBSD: patch-nix_nixnode.cc,v 1.1 2013/09/17 21:13:45 joerg Exp $

--- nix/nixnode.cc.orig	2013-09-17 20:01:46.000000000 +0000
+++ nix/nixnode.cc
@@ -156,8 +156,6 @@ Edge* pE;
   if (last.first == NODE_NONE)
     {
       prev = m_Adj.begin();
-      if (prev == (EdgeVec_it) NULL) // ! How can this happen?
-        return(NodeWeight_t(NODE_NONE, 0));
       pE = *prev;
       if(0)printf("NextAdj returning first edge %ld\n",
              pE->m_n);
