$NetBSD: patch-librecad_src_lib_engine_rs__image.h,v 1.1 2017/09/10 14:10:43 joerg Exp $

Default destructor can't be created in all instances, so make it explicit.

--- librecad/src/lib/engine/rs_image.h.orig	2017-09-10 10:42:08.481789997 +0000
+++ librecad/src/lib/engine/rs_image.h
@@ -39,6 +39,7 @@ struct RS_ImageData {
      * Default constructor. Leaves the data object uninitialized.
      */
 	RS_ImageData() = default;
+	~RS_ImageData();
 
     RS_ImageData(int handle,
                                 const RS_Vector& insertionPoint,
