$NetBSD: patch-intern_itasc_kdl_jntarray.hpp,v 1.1 2014/01/10 20:06:46 joerg Exp $

--- intern/itasc/kdl/jntarray.hpp.orig	2013-11-20 14:54:27.000000000 +0000
+++ intern/itasc/kdl/jntarray.hpp
@@ -209,12 +209,13 @@ class MyTask : public RTT::TaskContext
          * @return true if each element of src1 is within eps of the same
 		 * element in src2, or if both src1 and src2 have no data (ie 0==rows())
          */
-        friend bool Equal(const JntArray& src1,const JntArray& src2,double eps=epsilon);
+        friend bool Equal(const JntArray& src1,const JntArray& src2,double eps);
 
         friend bool operator==(const JntArray& src1,const JntArray& src2);
         //friend bool operator!=(const JntArray& src1,const JntArray& src2);
         };
 
+    bool Equal(const JntArray& src1,const JntArray& src2,double eps=epsilon);
     bool operator==(const JntArray& src1,const JntArray& src2);
     //bool operator!=(const JntArray& src1,const JntArray& src2);
 
