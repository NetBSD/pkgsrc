$NetBSD: patch-intern_itasc_kdl_jntarrayvel.hpp,v 1.1 2014/01/10 20:06:46 joerg Exp $

--- intern/itasc/kdl/jntarrayvel.hpp.orig	2013-11-20 15:08:46.000000000 +0000
+++ intern/itasc/kdl/jntarrayvel.hpp
@@ -51,9 +51,11 @@ namespace KDL
         friend void Divide(const JntArrayVel& src,const double& factor,JntArrayVel& dest);
         friend void Divide(const JntArrayVel& src,const doubleVel& factor,JntArrayVel& dest);
         friend void SetToZero(JntArrayVel& array);
-        friend bool Equal(const JntArrayVel& src1,const JntArrayVel& src2,double eps=epsilon);
+        friend bool Equal(const JntArrayVel& src1,const JntArrayVel& src2,double eps);
 
     };
+
+    bool Equal(const JntArrayVel& src1,const JntArrayVel& src2,double eps=epsilon);
 }
 
 #endif
