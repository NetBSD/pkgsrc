$NetBSD: patch-include_openbabel_shared__ptr.h,v 1.1 2013/05/06 14:22:43 joerg Exp $

--- include/openbabel/shared_ptr.h.orig	2013-05-05 20:23:37.000000000 +0000
+++ include/openbabel/shared_ptr.h
@@ -21,10 +21,14 @@ GNU General Public License for more deta
   #define shared_ptr boost::shared_ptr
 #else
   #include <memory>
-  #if __GNUC__ == 4  //&& __GNUC_MINOR__ < 3  removed at the suggestion of Konstantin Tokarev
-    #include <tr1/memory>
+  #if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+    using std::shared_ptr;
+  #else
+    #if __GNUC__ == 4  //&& __GNUC_MINOR__ < 3  removed at the suggestion of Konstantin Tokarev
+      #include <tr1/memory>
+    #endif
+    using std::tr1::shared_ptr;
   #endif
-  using std::tr1::shared_ptr;
 #endif
 
 #endif // OB_SHARED_PTR_H
