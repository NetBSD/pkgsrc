$NetBSD: patch-extern_solid_src_complex_DT__Complex.cpp,v 1.1 2012/10/20 22:10:18 joerg Exp $

--- extern/solid/src/complex/DT_Complex.cpp.orig	2012-10-20 10:47:02.000000000 +0000
+++ extern/solid/src/complex/DT_Complex.cpp
@@ -123,15 +123,6 @@ inline DT_CBox computeCBox(const DT_Conv
     return DT_CBox(p->bbox()); 
 }
 
-inline DT_CBox computeCBox(MT_Scalar margin, const MT_Transform& xform) 
-{
-    const MT_Matrix3x3& basis = xform.getBasis();
-    return DT_CBox(MT_Point3(MT_Scalar(0.0), MT_Scalar(0.0), MT_Scalar(0.0)), 
-                   MT_Vector3(basis[0].length() * margin, 
-                              basis[1].length() * margin, 
-                              basis[2].length() * margin));
-} 
-
 void DT_Complex::refit()
 {
     DT_RootData<const DT_Convex *> rd(m_nodes, m_leaves);
