$NetBSD: patch-speech__tools_base__class_inst__tmpl_vector__dvector__t.cc,v 1.1 2012/05/04 16:01:04 joerg Exp $

--- speech_tools/base_class/inst_tmpl/vector_dvector_t.cc.orig	2012-04-27 12:36:12.000000000 +0000
+++ speech_tools/base_class/inst_tmpl/vector_dvector_t.cc
@@ -40,6 +40,11 @@
 #include "EST_types.h"
 #include "EST_TVector.h"
 
+static const EST_DVector def_val_DVector;
+static EST_DVector error_return_DVector;
+template <> const EST_DVector *EST_TVector<EST_DVector>::def_val = &def_val_DVector;
+template <> EST_DVector *EST_TVector<EST_DVector>::error_return = &error_return_DVector;
+
 #if defined(INSTANTIATE_TEMPLATES)
 
 #include "../base_class/EST_TVector.cc"
@@ -47,10 +52,6 @@
 template class EST_TVector<EST_DVector>;
 
 #endif
-static const EST_DVector def_val_DVector;
-static EST_DVector error_return_DVector;
-template <> const EST_DVector *EST_TVector<EST_DVector>::def_val = &def_val_DVector;
-template <> EST_DVector *EST_TVector<EST_DVector>::error_return = &error_return_DVector;
 
 int operator !=(const EST_DVector &fv1, 
 		const EST_DVector &fv2)
