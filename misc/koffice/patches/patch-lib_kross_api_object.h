$NetBSD: patch-lib_kross_api_object.h,v 1.1 2013/03/23 10:15:26 joerg Exp $

--- lib/kross/api/object.h.orig	2013-02-28 16:43:45.000000000 +0000
+++ lib/kross/api/object.h
@@ -135,6 +135,7 @@ namespace Kross { namespace Api {
 }}
 
 #include "exception.h"
+#include <cstdlib>
 
 namespace Kross { namespace Api {
 
@@ -142,7 +143,7 @@ template<class T> inline T* Object::from
 {
     T* t = (T*) object.data();
     if(! t)
-        throw KSharedPtr<Exception>( new Exception(QString("Object \"%1\" invalid.").arg(object ? object->getClassName() : "")) );
+        std::abort();
     return t;
 }
 
