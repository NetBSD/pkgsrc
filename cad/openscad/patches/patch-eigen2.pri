$NetBSD: patch-eigen2.pri,v 1.2 2012/02/28 10:57:19 reinoud Exp $

Explicitly set the Eigen2 include path for pkgsrc.

--- eigen2.pri.orig	2011-12-27 13:46:10.000000000 +0000
+++ eigen2.pri
@@ -31,6 +31,8 @@ eigen2 {
     linux*: EIGEN2_INCLUDEPATH = /usr/include/eigen2
   }
 
+  EIGEN2_INCLUDEPATH = @PREFIX@/include/eigen2
+
   # eigen2 being under 'include/eigen2' needs special prepending
   QMAKE_INCDIR_QT = $$EIGEN2_INCLUDEPATH $$QMAKE_INCDIR_QT
 
@@ -40,4 +42,5 @@ eigen2 {
       QMAKE_CXXFLAGS += -DEIGEN_DONT_ALIGN
     }
   }
+
 }
