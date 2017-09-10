$NetBSD: patch-librecad_src_lib_engine_rs__image.cpp,v 1.1 2017/09/10 14:10:43 joerg Exp $

--- librecad/src/lib/engine/rs_image.cpp.orig	2017-09-10 10:54:08.660814636 +0000
+++ librecad/src/lib/engine/rs_image.cpp
@@ -35,6 +35,8 @@
 #include "rs_painterqt.h"
 #include "rs_math.h"
 
+RS_ImageData::~RS_ImageData() = default;
+
 RS_ImageData::RS_ImageData(int _handle,
 						   const RS_Vector& _insertionPoint,
 						   const RS_Vector& _uVector,
