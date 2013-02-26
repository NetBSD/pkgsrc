$NetBSD: patch-src_Features_Feature.h,v 1.1 2013/02/26 11:15:19 joerg Exp $

--- src/Features/Feature.h.orig	2011-02-10 12:00:35.000000000 +0000
+++ src/Features/Feature.h
@@ -9,6 +9,14 @@
 #include <QtCore/QString>
 #include <QList>
 
+class Feature;
+
+namespace boost
+{
+    void intrusive_ptr_add_ref(Feature * p);
+    void intrusive_ptr_release(Feature * p);
+}
+
 #include <boost/intrusive_ptr.hpp>
 
 #define CAST_FEATURE(x) (dynamic_cast<Feature*>(x))
@@ -79,12 +87,6 @@ class RenderPriority
         int theLayer;
 };
 
-namespace boost
-{
-    void intrusive_ptr_add_ref(Feature * p);
-    void intrusive_ptr_release(Feature * p);
-}
-
 /// Used to store objects of the map
 class Feature : public IFeature
 {
