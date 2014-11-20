$NetBSD: patch-include_openbabel_shared__ptr.h,v 1.2 2014/11/20 09:05:56 mef Exp $

--- include/openbabel/shared_ptr.h.orig	2011-10-13 05:24:02.000000000 +0900
+++ include/openbabel/shared_ptr.h	2014-11-20 17:51:30.000000000 +0900
@@ -21,10 +21,19 @@ GNU General Public License for more deta
   #define shared_ptr boost::shared_ptr
 #else
   #include <memory>
-  #if __GNUC__ == 4  //&& __GNUC_MINOR__ < 3  removed at the suggestion of Konstantin Tokarev
-    #include <tr1/memory>
+  #if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+    using std::shared_ptr;
+  #else
+   #if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+     using std::shared_ptr;
+   #else
+     #if __GNUC__ == 4  //&& __GNUC_MINOR__ < 3  removed at the suggestion of Konstantin Tokarev
+       #include <tr1/memory>
+     #endif
+     using std::tr1::shared_ptr;
+
+    #endif
   #endif
-  using std::tr1::shared_ptr;
 #endif
 
 #endif // OB_SHARED_PTR_H
