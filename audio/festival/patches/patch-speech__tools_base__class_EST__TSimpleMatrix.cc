$NetBSD: patch-speech__tools_base__class_EST__TSimpleMatrix.cc,v 1.1 2012/05/04 16:01:04 joerg Exp $

--- speech_tools/base_class/EST_TSimpleMatrix.cc.orig	2012-04-27 12:32:06.000000000 +0000
+++ speech_tools/base_class/EST_TSimpleMatrix.cc
@@ -42,6 +42,7 @@
 
 #include "EST_TSimpleMatrix.h"
 #include "EST_TVector.h"
+#include <cstring>
 #include <fstream>
 #include <iostream>
 #include "EST_cutils.h"
@@ -98,7 +99,7 @@ void EST_TSimpleMatrix<T>::resize(int ne
 	{
 	  int copy_r = Lof(this->num_rows(), new_rows);
 
-	  just_resize(new_rows, new_cols, &old_vals);
+	  this->just_resize(new_rows, new_cols, &old_vals);
 
           for (q=0; q<(copy_r*new_cols*sizeof(T)); q++) /* memcpy */
               ((char *)this->p_memory)[q] = ((char *)old_vals)[q];
@@ -127,9 +128,9 @@ void EST_TSimpleMatrix<T>::resize(int ne
 	  int copy_r = Lof(this->num_rows(), new_rows);
 	  int copy_c = Lof(this->num_columns(), new_cols);
 	  
-	  just_resize(new_rows, new_cols, &old_vals);
+	  this->just_resize(new_rows, new_cols, &old_vals);
 
-	  set_values(old_vals,
+	  this->set_values(old_vals,
 		     old_row_step, old_column_step,
 		     0, copy_r,
 		     0, copy_c);
