$NetBSD: patch-src_operations_operations.pro,v 1.2 2019/09/05 13:39:10 nia Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- src/operations/operations.pro.orig	2019-07-18 15:47:56.000000000 +0000
+++ src/operations/operations.pro
@@ -45,7 +45,9 @@ else {
     CONFIG += plugin
 }
 TARGET = $${RLIBNAME}operations
-LIBS += -l$${RLIBNAME}core -l$${RLIBNAME}entity
+LIBS += -L../core -l$${RLIBNAME}core \
+	-L../entity -l$${RLIBNAME}entity
+INSTALLS += target
 OTHER_FILES += operations.dox
 DEFINES += QCADOPERATIONS_LIBRARY
 RC_FILE = operations.rc
