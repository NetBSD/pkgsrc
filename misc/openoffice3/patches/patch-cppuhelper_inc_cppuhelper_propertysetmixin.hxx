$NetBSD: patch-cppuhelper_inc_cppuhelper_propertysetmixin.hxx,v 1.1 2013/04/01 12:19:13 joerg Exp $

--- cppuhelper/inc/cppuhelper/propertysetmixin.hxx.orig	2013-03-30 15:42:48.000000000 +0000
+++ cppuhelper/inc/cppuhelper/propertysetmixin.hxx
@@ -479,7 +479,6 @@ protected:
 
 private:
     PropertySetMixin(PropertySetMixin &); // not defined
-    void operator =(PropertySetMixin); // not defined
 };
 
 #if defined _MSC_VER
