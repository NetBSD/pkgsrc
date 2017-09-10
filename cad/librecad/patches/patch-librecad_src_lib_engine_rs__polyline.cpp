$NetBSD: patch-librecad_src_lib_engine_rs__polyline.cpp,v 1.1 2017/09/10 14:10:43 joerg Exp $

--- librecad/src/lib/engine/rs_polyline.cpp.orig	2017-09-10 10:39:08.690420563 +0000
+++ librecad/src/lib/engine/rs_polyline.cpp
@@ -41,6 +41,8 @@ RS_PolylineData::RS_PolylineData():
 {
 }
 
+RS_PolylineData::~RS_PolylineData() = default;
+
 RS_PolylineData::RS_PolylineData(const RS_Vector& _startpoint,
 				const RS_Vector& _endpoint,
 				bool _closed):
