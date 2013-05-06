$NetBSD: patch-core_mixdevice.h,v 1.1 2013/05/06 14:54:57 joerg Exp $

--- core/mixdevice.h.orig	2013-05-04 01:42:48.000000000 +0000
+++ core/mixdevice.h
@@ -23,8 +23,12 @@
 
 // std::shared_ptr
 #include <memory>
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+using std::shared_ptr;
+#else
 #include <tr1/memory>
 using namespace ::std::tr1;
+#endif
 
 //KMix
 class Mixer;
