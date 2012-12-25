$NetBSD: patch-library_forms_mforms.cpp,v 1.1 2012/12/25 21:12:31 joerg Exp $

--- library/forms/mforms.cpp.orig	2012-12-25 15:55:34.000000000 +0000
+++ library/forms/mforms.cpp
@@ -23,6 +23,8 @@
 #include "mforms/mforms.h"
 #include "mforms/simpleform.h"
 
+extern GThread *_mforms_main_thread;
+
 using namespace mforms;
 
 // The first time this method is called must be from the main thread, during 
@@ -33,7 +35,6 @@ ControlFactory *ControlFactory::get_inst
   if (!instance)
   {
     // Do some one time initializations.
-    extern GThread *_mforms_main_thread;
     _mforms_main_thread= g_thread_self();
 
     instance= new ControlFactory();
