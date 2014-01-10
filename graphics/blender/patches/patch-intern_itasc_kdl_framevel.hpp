$NetBSD: patch-intern_itasc_kdl_framevel.hpp,v 1.1 2014/01/10 20:06:46 joerg Exp $

--- intern/itasc/kdl/framevel.hpp.orig	2013-11-20 14:52:47.000000000 +0000
+++ intern/itasc/kdl/framevel.hpp
@@ -110,15 +110,18 @@ public:
     IMETHOD friend void SetToZero(VectorVel& v);
 
 
-    IMETHOD friend bool Equal(const VectorVel& r1,const VectorVel& r2,double eps=epsilon);
-    IMETHOD friend bool Equal(const Vector& r1,const VectorVel& r2,double eps=epsilon);
-    IMETHOD friend bool Equal(const VectorVel& r1,const Vector& r2,double eps=epsilon);
+    IMETHOD friend bool Equal(const VectorVel& r1,const VectorVel& r2,double eps);
+    IMETHOD friend bool Equal(const Vector& r1,const VectorVel& r2,double eps);
+    IMETHOD friend bool Equal(const VectorVel& r1,const Vector& r2,double eps);
     IMETHOD friend VectorVel operator - (const VectorVel& r);
     IMETHOD friend doubleVel dot(const VectorVel& lhs,const VectorVel& rhs);
     IMETHOD friend doubleVel dot(const VectorVel& lhs,const Vector& rhs);
     IMETHOD friend doubleVel dot(const Vector& lhs,const VectorVel& rhs);
 };
 
+bool Equal(const VectorVel& r1,const VectorVel& r2,double eps=epsilon);
+bool Equal(const Vector& r1,const VectorVel& r2,double eps=epsilon);
+bool Equal(const VectorVel& r1,const Vector& r2,double eps=epsilon);
 
 
 class RotationVel
@@ -166,9 +169,9 @@ public:
     IMETHOD friend RotationVel operator* (const RotationVel& r1,const RotationVel& r2);
     IMETHOD friend RotationVel operator* (const Rotation& r1,const RotationVel& r2);
     IMETHOD friend RotationVel operator* (const RotationVel& r1,const Rotation& r2);
-    IMETHOD friend bool Equal(const RotationVel& r1,const RotationVel& r2,double eps=epsilon);
-    IMETHOD friend bool Equal(const Rotation& r1,const RotationVel& r2,double eps=epsilon);
-    IMETHOD friend bool Equal(const RotationVel& r1,const Rotation& r2,double eps=epsilon);
+    IMETHOD friend bool Equal(const RotationVel& r1,const RotationVel& r2,double eps);
+    IMETHOD friend bool Equal(const Rotation& r1,const RotationVel& r2,double eps);
+    IMETHOD friend bool Equal(const RotationVel& r1,const Rotation& r2,double eps);
 
     IMETHOD TwistVel Inverse(const TwistVel& arg) const;
     IMETHOD TwistVel Inverse(const Twist& arg) const;
@@ -176,6 +179,9 @@ public:
     IMETHOD TwistVel operator * (const Twist& arg) const;
 };
 
+bool Equal(const RotationVel& r1,const RotationVel& r2,double eps=epsilon);
+bool Equal(const Rotation& r1,const RotationVel& r2,double eps=epsilon);
+bool Equal(const RotationVel& r1,const Rotation& r2,double eps=epsilon);
 
 
 
@@ -220,9 +226,9 @@ public:
     IMETHOD friend FrameVel operator * (const FrameVel& f1,const FrameVel& f2);
     IMETHOD friend FrameVel operator * (const Frame& f1,const FrameVel& f2);
     IMETHOD friend FrameVel operator * (const FrameVel& f1,const Frame& f2);
-    IMETHOD friend bool Equal(const FrameVel& r1,const FrameVel& r2,double eps=epsilon);
-    IMETHOD friend bool Equal(const Frame& r1,const FrameVel& r2,double eps=epsilon);
-    IMETHOD friend bool Equal(const FrameVel& r1,const Frame& r2,double eps=epsilon);
+    IMETHOD friend bool Equal(const FrameVel& r1,const FrameVel& r2,double eps);
+    IMETHOD friend bool Equal(const Frame& r1,const FrameVel& r2,double eps);
+    IMETHOD friend bool Equal(const FrameVel& r1,const Frame& r2,double eps);
 
     IMETHOD TwistVel  Inverse(const TwistVel& arg) const;
     IMETHOD TwistVel  Inverse(const Twist& arg) const;
@@ -230,6 +236,9 @@ public:
     IMETHOD TwistVel operator * (const Twist& arg) const;
 };
 
+bool Equal(const FrameVel& r1,const FrameVel& r2,double eps=epsilon);
+bool Equal(const Frame& r1,const FrameVel& r2,double eps=epsilon);
+bool Equal(const FrameVel& r1,const Frame& r2,double eps=epsilon);
 
 
 
@@ -292,9 +301,9 @@ public:
      // = Equality operators
      // do not use operator == because the definition of Equal(.,.) is slightly
      // different.  It compares whether the 2 arguments are equal in an eps-interval
-     IMETHOD friend bool Equal(const TwistVel& a,const TwistVel& b,double eps=epsilon);
-     IMETHOD friend bool Equal(const Twist& a,const TwistVel& b,double eps=epsilon);
-     IMETHOD friend bool Equal(const TwistVel& a,const Twist& b,double eps=epsilon);
+     IMETHOD friend bool Equal(const TwistVel& a,const TwistVel& b,double eps);
+     IMETHOD friend bool Equal(const Twist& a,const TwistVel& b,double eps);
+     IMETHOD friend bool Equal(const TwistVel& a,const Twist& b,double eps);
 
 // = Conversion to other entities
      IMETHOD Twist GetTwist() const;
@@ -305,6 +314,10 @@ public:
 
 };
 
+bool Equal(const TwistVel& a,const TwistVel& b,double eps=epsilon);
+bool Equal(const Twist& a,const TwistVel& b,double eps=epsilon);
+bool Equal(const TwistVel& a,const Twist& b,double eps=epsilon);
+
 IMETHOD VectorVel diff(const VectorVel& a,const VectorVel& b,double dt=1.0) {
 	return VectorVel(diff(a.p,b.p,dt),diff(a.v,b.v,dt));
 }
