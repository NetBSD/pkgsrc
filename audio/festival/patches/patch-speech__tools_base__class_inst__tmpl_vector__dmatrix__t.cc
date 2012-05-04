$NetBSD: patch-speech__tools_base__class_inst__tmpl_vector__dmatrix__t.cc,v 1.1 2012/05/04 16:01:04 joerg Exp $

--- speech_tools/base_class/inst_tmpl/vector_dmatrix_t.cc.orig	2012-04-27 12:36:31.000000000 +0000
+++ speech_tools/base_class/inst_tmpl/vector_dmatrix_t.cc
@@ -40,6 +40,11 @@
 #include "EST_types.h"
 #include "EST_TVector.h"
 
+static const EST_DMatrix def_val_DMatrix;
+static EST_DMatrix error_return_DMatrix;
+template <> const EST_DMatrix *EST_TVector<EST_DMatrix>::def_val = &def_val_DMatrix;
+template <> EST_DMatrix *EST_TVector<EST_DMatrix>::error_return = &error_return_DMatrix;
+
 #if defined(INSTANTIATE_TEMPLATES)
 
 #include "../base_class/EST_TVector.cc"
@@ -47,10 +52,6 @@
 template class EST_TVector<EST_DMatrix>;
 
 #endif
-static const EST_DMatrix def_val_DMatrix;
-static EST_DMatrix error_return_DMatrix;
-template <> const EST_DMatrix *EST_TVector<EST_DMatrix>::def_val = &def_val_DMatrix;
-template <> EST_DMatrix *EST_TVector<EST_DMatrix>::error_return = &error_return_DMatrix;
 
 int operator !=(const EST_DMatrix &fm1, 
 		const EST_DMatrix &fm2)
