$NetBSD: patch-eigen2.pri,v 1.1.1.1 2012/02/27 14:44:29 reinoud Exp $

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
