$NetBSD: patch-librecad_src_lib_engine_rs__polyline.h,v 1.1 2017/09/10 14:10:43 joerg Exp $

Default destructor can't be created in all instances, so make it explicit.

--- librecad/src/lib/engine/rs_polyline.h.orig	2017-09-10 10:37:45.908701029 +0000
+++ librecad/src/lib/engine/rs_polyline.h
@@ -38,7 +38,7 @@
  */
 struct RS_PolylineData : public RS_Flags {
 	RS_PolylineData();
-	~RS_PolylineData()=default;
+	virtual ~RS_PolylineData();
 	RS_PolylineData(const RS_Vector& startpoint,
                     const RS_Vector& endpoint,
 					bool closed);
