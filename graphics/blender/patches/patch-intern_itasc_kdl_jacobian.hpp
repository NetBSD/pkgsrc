$NetBSD: patch-intern_itasc_kdl_jacobian.hpp,v 1.1 2014/01/10 20:06:46 joerg Exp $

--- intern/itasc/kdl/jacobian.hpp.orig	2013-11-20 14:57:39.000000000 +0000
+++ intern/itasc/kdl/jacobian.hpp
@@ -45,7 +45,7 @@ namespace KDL
         bool operator ==(const Jacobian& arg);
         bool operator !=(const Jacobian& arg);
         
-        friend bool Equal(const Jacobian& a,const Jacobian& b,double eps=epsilon);
+        friend bool Equal(const Jacobian& a,const Jacobian& b,double eps);
         
 
         ~Jacobian();
@@ -63,6 +63,9 @@ namespace KDL
 
 
     };
+
+    bool Equal(const Jacobian& a,const Jacobian& b,double eps=epsilon);
 }
 
+
 #endif
