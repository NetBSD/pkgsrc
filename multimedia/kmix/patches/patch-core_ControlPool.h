$NetBSD: patch-core_ControlPool.h,v 1.1 2013/05/06 14:54:57 joerg Exp $

--- core/ControlPool.h.orig	2013-05-04 01:52:19.000000000 +0000
+++ core/ControlPool.h
@@ -25,9 +25,12 @@
 
 // std::shared_ptr
 #include <memory>
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+using std::shared_ptr;
+#else
 #include <tr1/memory>
-
 using namespace ::std::tr1;
+#endif
 
 #include "core/mixdevice.h"
 
