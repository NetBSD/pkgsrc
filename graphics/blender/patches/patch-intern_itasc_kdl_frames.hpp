$NetBSD: patch-intern_itasc_kdl_frames.hpp,v 1.1 2014/01/10 20:06:46 joerg Exp $

--- intern/itasc/kdl/frames.hpp.orig	2013-11-20 14:46:29.000000000 +0000
+++ intern/itasc/kdl/frames.hpp
@@ -248,10 +248,10 @@ public:
 
      //! do not use operator == because the definition of Equal(.,.) is slightly
      //! different.  It compares whether the 2 arguments are equal in an eps-interval
-     inline friend bool Equal(const Vector& a,const Vector& b,double eps=epsilon);
+     inline friend bool Equal(const Vector& a,const Vector& b,double eps);
 
 	 //! return a normalized vector
-	 inline friend Vector Normalize(const Vector& a, double eps=epsilon);
+	 inline friend Vector Normalize(const Vector& a, double eps);
 
 	 //! The literal equality operator==(), also identical.
      inline friend bool operator==(const Vector& a,const Vector& b);
@@ -502,7 +502,7 @@ public:
 
      //! do not use operator == because the definition of Equal(.,.) is slightly
      //! different.  It compares whether the 2 arguments are equal in an eps-interval
-     friend bool Equal(const Rotation& a,const Rotation& b,double eps=epsilon);
+     friend bool Equal(const Rotation& a,const Rotation& b,double eps);
 
 	 //! The literal equality operator==(), also identical.
      friend bool operator==(const Rotation& a,const Rotation& b);
@@ -663,7 +663,7 @@ public:
 
      //! do not use operator == because the definition of Equal(.,.) is slightly
      //! different.  It compares whether the 2 arguments are equal in an eps-interval
-     inline friend bool Equal(const Frame& a,const Frame& b,double eps=epsilon);
+     inline friend bool Equal(const Frame& a,const Frame& b,double eps);
 
 	 //! The literal equality operator==(), also identical.
      inline friend bool operator==(const Frame& a,const Frame& b);
@@ -735,7 +735,7 @@ public:
 
      //! do not use operator == because the definition of Equal(.,.) is slightly
      //! different.  It compares whether the 2 arguments are equal in an eps-interval
-     inline friend bool Equal(const Twist& a,const Twist& b,double eps=epsilon);
+     inline friend bool Equal(const Twist& a,const Twist& b,double eps);
 
 	 //! The literal equality operator==(), also identical.
      inline friend bool operator==(const Twist& a,const Twist& b);
@@ -898,7 +898,7 @@ public:
 
      //! do not use operator == because the definition of Equal(.,.) is slightly
      //! different.  It compares whether the 2 arguments are equal in an eps-interval
-     inline friend bool Equal(const Wrench& a,const Wrench& b,double eps=epsilon);
+     inline friend bool Equal(const Wrench& a,const Wrench& b,double eps);
 
 	 //! The literal equality operator==(), also identical.
      inline friend bool operator==(const Wrench& a,const Wrench& b);
@@ -979,7 +979,7 @@ public:
 
      //! do not use operator == because the definition of Equal(.,.) is slightly
      //! different.  It compares whether the 2 arguments are equal in an eps-interval
-     inline friend bool Equal(const Vector2& a,const Vector2& b,double eps=epsilon);
+     inline friend bool Equal(const Vector2& a,const Vector2& b,double eps);
 
     friend class Rotation2;
 };
@@ -1026,7 +1026,7 @@ public:
 
      //! do not use operator == because the definition of Equal(.,.) is slightly
      //! different.  It compares whether the 2 arguments are equal in an eps-interval
-     inline friend bool Equal(const Rotation2& a,const Rotation2& b,double eps=epsilon);
+     inline friend bool Equal(const Rotation2& a,const Rotation2& b,double eps);
 };
 
 //! A 2D frame class, for further documentation see the Frames class
@@ -1067,9 +1067,20 @@ public:
         tmp.SetIdentity();
         return tmp;
      }
-     inline friend bool Equal(const Frame2& a,const Frame2& b,double eps=epsilon);
+     inline friend bool Equal(const Frame2& a,const Frame2& b,double eps);
 };
 
+
+Vector Normalize(const Vector& a, double eps=epsilon);
+bool Equal(const Vector& a,const Vector& b,double eps=epsilon);
+bool Equal(const Rotation& a,const Rotation& b,double eps=epsilon);
+bool Equal(const Frame& a,const Frame& b,double eps=epsilon);
+bool Equal(const Twist& a,const Twist& b,double eps=epsilon);
+bool Equal(const Wrench& a,const Wrench& b,double eps=epsilon);
+bool Equal(const Vector2& a,const Vector2& b,double eps=epsilon);
+bool Equal(const Rotation2& a,const Rotation2& b,double eps=epsilon);
+bool Equal(const Frame2& a,const Frame2& b,double eps=epsilon);
+
 IMETHOD Vector diff(const Vector& a,const Vector& b,double dt=1);
 IMETHOD Vector diff(const Rotation& R_a_b1,const Rotation& R_a_b2,double dt=1);
 IMETHOD Twist diff(const Frame& F_a_b1,const Frame& F_a_b2,double dt=1);
