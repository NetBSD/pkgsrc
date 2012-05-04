$NetBSD: patch-speech__tools_stats_dynamic__program.cc,v 1.1 2012/05/04 16:01:04 joerg Exp $

--- speech_tools/stats/dynamic_program.cc.orig	2012-04-27 12:49:30.000000000 +0000
+++ speech_tools/stats/dynamic_program.cc
@@ -42,6 +42,12 @@
 #include "ling_class/EST_Utterance.h"
 
 typedef EST_TVector<EST_Item*> EST_Item_ptr_Vector;
+
+static EST_Item *const def_val_item_ptr = NULL;
+template <> EST_Item* const *EST_Item_ptr_Vector::def_val = &def_val_item_ptr;
+static EST_Item* error_return_item_ptr = NULL;
+template <> EST_Item* *EST_Item_ptr_Vector::error_return = &error_return_item_ptr;
+
 #if defined(INSTANTIATE_TEMPLATES)
 #include "../base_class/EST_TVector.cc"
 
@@ -49,12 +55,6 @@ template class EST_TVector<EST_Item*>;
 
 #endif
 
-static EST_Item *const def_val_item_ptr = NULL;
-template <> EST_Item* const *EST_Item_ptr_Vector::def_val = &def_val_item_ptr;
-
-static EST_Item* error_return_item_ptr = NULL;
-template <> EST_Item* *EST_Item_ptr_Vector::error_return = &error_return_item_ptr;
-
 typedef
 float (*local_cost_function)(const EST_Item *item1,
 			     const EST_Item *item2);
