$NetBSD: patch-include_CGAL_Mesh__2_Do__not__refine__edges.h,v 1.1 2014/02/08 12:16:12 wiedi Exp $

fix building other packages with gcc 4.7 linking cgal
see also: http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=673554
--- include/CGAL/Mesh_2/Do_not_refine_edges.h.orig	2010-05-14 19:00:16.000000000 +0000
+++ include/CGAL/Mesh_2/Do_not_refine_edges.h
@@ -79,7 +79,7 @@ public:
       const Face_handle& fh = eit->first;
       const int& i = eit->second;
 
-      if(fh->is_constrained(i) && !is_locally_conform(this->tr, fh, i, p))
+      if(fh->is_constrained(i) && !this->is_locally_conform(this->tr, fh, i, p))
       {
         return CONFLICT_AND_ELEMENT_SHOULD_BE_DROPPED;
       }
