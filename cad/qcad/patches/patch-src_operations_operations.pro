$NetBSD: patch-src_operations_operations.pro,v 1.1 2016/08/30 10:56:04 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/operations/operations.pro.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/operations/operations.pro
@@ -41,6 +41,8 @@ else {
     CONFIG += plugin
 }
 TARGET = $${RLIBNAME}operations
-LIBS += -l$${RLIBNAME}core -l$${RLIBNAME}entity
+LIBS += -L../core -l$${RLIBNAME}core \
+	-L../entity -l$${RLIBNAME}entity
+INSTALLS += target
 OTHER_FILES += operations.dox
 DEFINES += QCADOPERATIONS_LIBRARY
