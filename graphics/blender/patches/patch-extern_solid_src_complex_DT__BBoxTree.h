$NetBSD: patch-extern_solid_src_complex_DT__BBoxTree.h,v 1.1 2012/10/20 22:10:18 joerg Exp $

--- extern/solid/src/complex/DT_BBoxTree.h.orig	2012-10-20 10:46:59.000000000 +0000
+++ extern/solid/src/complex/DT_BBoxTree.h
@@ -95,6 +95,15 @@ public:
     const Shape         *m_leaves;
 };
 
+inline DT_CBox computeCBox(MT_Scalar margin, const MT_Transform& xform) 
+{
+    const MT_Matrix3x3& basis = xform.getBasis();
+    return DT_CBox(MT_Point3(MT_Scalar(0.0), MT_Scalar(0.0), MT_Scalar(0.0)), 
+                   MT_Vector3(basis[0].length() * margin, 
+                              basis[1].length() * margin, 
+                              basis[2].length() * margin));
+} 
+
 template <typename Shape1, typename Shape2>
 class DT_ObjectData : public DT_RootData<Shape1> {
 public:
