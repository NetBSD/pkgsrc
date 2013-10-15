$NetBSD: patch-lib_gui_xwindow.h,v 1.1 2013/10/15 14:46:07 joerg Exp $

--- lib/gui/xwindow.h.orig	2013-10-15 12:51:15.000000000 +0000
+++ lib/gui/xwindow.h
@@ -39,7 +39,14 @@
 #include <stdint.h>
 #include "config.h"
 
+#include <cstddef>
+#if __cplusplus >= 201103L || defined(_LIBCPP_VERSION)
+#include <memory>
+using std::shared_ptr;
+#else
 #include <tr1/memory>
+using std::tr1::shared_ptr;
+#endif
 
 #include <ptlib.h>
 #include <ptlib/vconvert.h>
@@ -245,7 +252,7 @@ private:
   int _planes;
 
   PColourConverter* _colorConverter;
-  std::tr1::shared_ptr<void> _frameBuffer;
+  shared_ptr<void> _frameBuffer;
   
 #ifdef HAVE_SHM
   XShmSegmentInfo _XShmInfo;
