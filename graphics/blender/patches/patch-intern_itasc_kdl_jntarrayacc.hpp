$NetBSD: patch-intern_itasc_kdl_jntarrayacc.hpp,v 1.1 2014/01/10 20:06:46 joerg Exp $

--- intern/itasc/kdl/jntarrayacc.hpp.orig	2013-11-20 15:09:06.000000000 +0000
+++ intern/itasc/kdl/jntarrayacc.hpp
@@ -58,9 +58,11 @@ namespace KDL
         friend void Divide(const JntArrayAcc& src,const doubleVel& factor,JntArrayAcc& dest);
         friend void Divide(const JntArrayAcc& src,const doubleAcc& factor,JntArrayAcc& dest);
         friend void SetToZero(JntArrayAcc& array);
-        friend bool Equal(const JntArrayAcc& src1,const JntArrayAcc& src2,double eps=epsilon);
+        friend bool Equal(const JntArrayAcc& src1,const JntArrayAcc& src2,double eps);
 
     };
+
+    bool Equal(const JntArrayAcc& src1,const JntArrayAcc& src2,double eps=epsilon);
 }
 
 #endif
