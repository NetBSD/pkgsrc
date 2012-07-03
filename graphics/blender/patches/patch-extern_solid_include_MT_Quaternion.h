$NetBSD: patch-extern_solid_include_MT_Quaternion.h,v 1.1 2012/07/03 18:10:03 joerg Exp $

--- extern/solid/include/MT/Quaternion.h.orig	2012-07-03 13:16:43.000000000 +0000
+++ extern/solid/include/MT/Quaternion.h
@@ -158,7 +158,7 @@ namespace MT {
 
 		Quaternion<Scalar> inverse() const
 		{
-			return conjugate / length2();
+			return conjugate() / length2();
 		}
 		
 		Quaternion<Scalar> slerp(const Quaternion<Scalar>& q, const Scalar& t) const
