$NetBSD: patch-intern_itasc_kdl_frameacc.hpp,v 1.1 2014/01/10 20:06:46 joerg Exp $

--- intern/itasc/kdl/frameacc.hpp.orig	2013-11-20 15:03:18.000000000 +0000
+++ intern/itasc/kdl/frameacc.hpp
@@ -78,15 +78,18 @@ public:
     IMETHOD friend VectorAcc operator / (const VectorAcc& r2,const doubleAcc& r1);
 
 
-    IMETHOD friend bool Equal(const VectorAcc& r1,const VectorAcc& r2,double eps=epsilon);
-    IMETHOD friend bool Equal(const Vector& r1,const VectorAcc& r2,double eps=epsilon);
-    IMETHOD friend bool Equal(const VectorAcc& r1,const Vector& r2,double eps=epsilon);
+    IMETHOD friend bool Equal(const VectorAcc& r1,const VectorAcc& r2,double eps);
+    IMETHOD friend bool Equal(const Vector& r1,const VectorAcc& r2,double eps);
+    IMETHOD friend bool Equal(const VectorAcc& r1,const Vector& r2,double eps);
     IMETHOD friend VectorAcc operator - (const VectorAcc& r);
     IMETHOD friend doubleAcc dot(const VectorAcc& lhs,const VectorAcc& rhs);
     IMETHOD friend doubleAcc dot(const VectorAcc& lhs,const Vector& rhs);
     IMETHOD friend doubleAcc dot(const Vector& lhs,const VectorAcc& rhs);
 };
 
+bool Equal(const VectorAcc& r1,const VectorAcc& r2,double eps=epsilon);
+bool Equal(const Vector& r1,const VectorAcc& r2,double eps=epsilon);
+bool Equal(const VectorAcc& r1,const Vector& r2,double eps=epsilon);
 
 
 class RotationAcc
@@ -132,15 +135,18 @@ public:
     IMETHOD friend RotationAcc operator* (const RotationAcc& r1,const RotationAcc& r2);
     IMETHOD friend RotationAcc operator* (const Rotation& r1,const RotationAcc& r2);
     IMETHOD friend RotationAcc operator* (const RotationAcc& r1,const Rotation& r2);
-    IMETHOD friend bool Equal(const RotationAcc& r1,const RotationAcc& r2,double eps=epsilon);
-    IMETHOD friend bool Equal(const Rotation& r1,const RotationAcc& r2,double eps=epsilon);
-    IMETHOD friend bool Equal(const RotationAcc& r1,const Rotation& r2,double eps=epsilon);
+    IMETHOD friend bool Equal(const RotationAcc& r1,const RotationAcc& r2,double eps);
+    IMETHOD friend bool Equal(const Rotation& r1,const RotationAcc& r2,double eps);
+    IMETHOD friend bool Equal(const RotationAcc& r1,const Rotation& r2,double eps);
     IMETHOD TwistAcc Inverse(const TwistAcc& arg) const;
     IMETHOD TwistAcc Inverse(const Twist& arg) const;
     IMETHOD TwistAcc operator * (const TwistAcc& arg) const;
     IMETHOD TwistAcc operator * (const Twist& arg) const;
 };
 
+bool Equal(const RotationAcc& r1,const RotationAcc& r2,double eps=epsilon);
+bool Equal(const Rotation& r1,const RotationAcc& r2,double eps=epsilon);
+bool Equal(const RotationAcc& r1,const Rotation& r2,double eps=epsilon);
 
 
 
@@ -170,9 +176,9 @@ public:
     IMETHOD friend FrameAcc operator * (const FrameAcc& f1,const FrameAcc& f2);
     IMETHOD friend FrameAcc operator * (const Frame& f1,const FrameAcc& f2);
     IMETHOD friend FrameAcc operator * (const FrameAcc& f1,const Frame& f2);
-    IMETHOD friend bool Equal(const FrameAcc& r1,const FrameAcc& r2,double eps=epsilon);
-    IMETHOD friend bool Equal(const Frame& r1,const FrameAcc& r2,double eps=epsilon);
-    IMETHOD friend bool Equal(const FrameAcc& r1,const Frame& r2,double eps=epsilon);
+    IMETHOD friend bool Equal(const FrameAcc& r1,const FrameAcc& r2,double eps);
+    IMETHOD friend bool Equal(const Frame& r1,const FrameAcc& r2,double eps);
+    IMETHOD friend bool Equal(const FrameAcc& r1,const Frame& r2,double eps);
 
     IMETHOD TwistAcc  Inverse(const TwistAcc& arg) const;
     IMETHOD TwistAcc  Inverse(const Twist& arg) const;
@@ -180,6 +186,9 @@ public:
     IMETHOD TwistAcc operator * (const Twist& arg) const;
 };
 
+bool Equal(const FrameAcc& r1,const FrameAcc& r2,double eps=epsilon);
+bool Equal(const Frame& r1,const FrameAcc& r2,double eps=epsilon);
+bool Equal(const FrameAcc& r1,const Frame& r2,double eps=epsilon);
 
 
 
@@ -226,9 +235,9 @@ public:
      // the new point.
      // Complexity : 6M+6A
 
-     IMETHOD friend bool Equal(const TwistAcc& a,const TwistAcc& b,double eps=epsilon);
-     IMETHOD friend bool Equal(const Twist& a,const TwistAcc& b,double eps=epsilon);
-     IMETHOD friend bool Equal(const TwistAcc& a,const Twist& b,double eps=epsilon);
+     IMETHOD friend bool Equal(const TwistAcc& a,const TwistAcc& b,double eps);
+     IMETHOD friend bool Equal(const Twist& a,const TwistAcc& b,double eps);
+     IMETHOD friend bool Equal(const TwistAcc& a,const Twist& b,double eps);
 
 
      IMETHOD Twist GetTwist() const;
@@ -239,6 +248,9 @@ public:
 
 };
 
+bool Equal(const TwistAcc& a,const TwistAcc& b,double eps=epsilon);
+bool Equal(const Twist& a,const TwistAcc& b,double eps=epsilon);
+bool Equal(const TwistAcc& a,const Twist& b,double eps=epsilon);
 
 
 
