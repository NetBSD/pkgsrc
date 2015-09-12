$NetBSD: patch-Source_CursesDialog_cmCursesWidget.cxx,v 1.2 2015/09/12 16:46:11 wiz Exp $

Compensate for missing const attribute in NetBSD.
http://public.kitware.com/Bug/view.php?id=15740

--- Source/CursesDialog/cmCursesWidget.cxx.orig	2015-09-07 09:53:22.000000000 +0000
+++ Source/CursesDialog/cmCursesWidget.cxx
@@ -49,7 +49,7 @@ void cmCursesWidget::Move(int x, int y, 
 void cmCursesWidget::SetValue(const std::string& value)
 {
   this->Value = value;
-  set_field_buffer(this->Field, 0, value.c_str());
+  set_field_buffer(this->Field, 0, const_cast<char *>(value.c_str()));
 }
 
 const char* cmCursesWidget::GetValue()
