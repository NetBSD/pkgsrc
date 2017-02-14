$NetBSD: patch-dselect_cxx-support.cc,v 1.1 2017/02/14 21:26:22 joerg Exp $

Do not depend on cxxabi.h to have declared __cxa_pure_virtual.

--- dselect/cxx-support.cc.orig	2017-02-09 16:14:23.124533168 +0000
+++ dselect/cxx-support.cc
@@ -81,9 +81,11 @@ operator delete[](void *a, size_t size) 
 }
 
 #ifdef HAVE___CXA_PURE_VIRTUAL
+namespace __cxxabiv1 {
 extern "C" void
-abi::__cxa_pure_virtual()
+__cxa_pure_virtual()
 {
 	internerr("pure virtual function called");
 }
+}
 #endif
