$NetBSD: patch-chart2_source_controller_chartapiwrapper_WrappedSymbolProperties.hxx,v 1.1 2013/04/01 12:19:13 joerg Exp $

--- chart2/source/controller/chartapiwrapper/WrappedSymbolProperties.hxx.orig	2013-03-30 19:43:59.000000000 +0000
+++ chart2/source/controller/chartapiwrapper/WrappedSymbolProperties.hxx
@@ -36,6 +36,20 @@
 #include <boost/shared_ptr.hpp>
 #include <vector>
 
+namespace com {
+  namespace sun {
+    namespace star {
+      namespace awt {
+// this operator is not defined by default
+inline bool operator!=( const Size & rSize1, const Size & rSize2 )
+{
+    return (rSize1.Width != rSize2.Width) || (rSize1.Height != rSize2.Height);
+}
+      }
+    }
+  }
+}
+
 //.............................................................................
 namespace chart
 {
