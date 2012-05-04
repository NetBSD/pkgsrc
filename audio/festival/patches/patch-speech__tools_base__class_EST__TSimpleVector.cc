$NetBSD: patch-speech__tools_base__class_EST__TSimpleVector.cc,v 1.1 2012/05/04 16:01:04 joerg Exp $

--- speech_tools/base_class/EST_TSimpleVector.cc.orig	2012-04-27 12:32:56.000000000 +0000
+++ speech_tools/base_class/EST_TSimpleVector.cc
@@ -42,6 +42,7 @@
 
 #include "EST_TSimpleVector.h"
 #include "EST_matrix_support.h"
+#include <cstring>
 #include <fstream>
 #include "EST_cutils.h"
 
@@ -70,7 +71,7 @@ template<class T> void EST_TSimpleVector
   int old_offset = this->p_offset;
   unsigned int q;
 
-  just_resize(newn, &old_vals);
+  this->just_resize(newn, &old_vals);
 
   if (set && old_vals)
     {
