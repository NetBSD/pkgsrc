$NetBSD: patch-core_src_util_lp_permutation__matrix.h,v 1.1 2020/03/18 19:29:18 joerg Exp $

Fixes no conversion from const vector<unsigned> to unsigned int *.

--- core/src/util/lp/permutation_matrix.h.orig	2020-03-18 15:38:20.643552591 +0000
+++ core/src/util/lp/permutation_matrix.h
@@ -117,7 +117,7 @@ class permutation_matrix : public tail_m
 
         unsigned size() const { return static_cast<unsigned>(m_rev.size()); }
 
-        unsigned * values() const { return m_permutation; }
+        unsigned * values() { return &m_permutation[0]; }
 
         void resize(unsigned size) {
             unsigned old_size = m_permutation.size();
