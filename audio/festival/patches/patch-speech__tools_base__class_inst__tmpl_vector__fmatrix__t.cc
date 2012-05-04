$NetBSD: patch-speech__tools_base__class_inst__tmpl_vector__fmatrix__t.cc,v 1.1 2012/05/04 16:01:04 joerg Exp $

--- speech_tools/base_class/inst_tmpl/vector_fmatrix_t.cc.orig	2012-04-27 12:34:44.000000000 +0000
+++ speech_tools/base_class/inst_tmpl/vector_fmatrix_t.cc
@@ -40,6 +40,10 @@
 #include "EST_types.h"
 #include "EST_TVector.h"
 
+static EST_FMatrix error_return_FMatrix;
+static const EST_FMatrix def_val_FMatrix;
+template <> const EST_FMatrix *EST_TVector<EST_FMatrix>::def_val = &def_val_FMatrix;
+template <> EST_FMatrix *EST_TVector<EST_FMatrix>::error_return = &error_return_FMatrix;
 #if defined(INSTANTIATE_TEMPLATES)
 
 #include "../base_class/EST_TVector.cc"
@@ -48,10 +52,6 @@ template class EST_TVector<EST_FMatrix>;
 
 
 #endif
-static const EST_FMatrix def_val_FMatrix;
-static EST_FMatrix error_return_FMatrix;
-template <> const EST_FMatrix *EST_TVector<EST_FMatrix>::def_val = &def_val_FMatrix;
-template <> EST_FMatrix *EST_TVector<EST_FMatrix>::error_return = &error_return_FMatrix;
 
 int operator !=(const EST_FMatrix &fm1, 
 		const EST_FMatrix &fm2)
