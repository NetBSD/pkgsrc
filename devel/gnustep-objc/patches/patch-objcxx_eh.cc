$NetBSD: patch-objcxx_eh.cc,v 1.2 2020/04/17 13:32:23 joerg Exp $

Workaround build failure due to redefinition and include correct header.

--- objcxx_eh.cc.orig	2015-08-07 11:33:41.000000000 +0000
+++ objcxx_eh.cc
@@ -3,6 +3,7 @@
 #include "dwarf_eh.h"
 #include "objcxx_eh.h"
 #include <exception>
+#include <typeinfo>
 
 extern "C" 
 {
@@ -15,6 +16,7 @@ namespace __cxxabiv1
 
 using __cxxabiv1::__class_type_info;
 
+#if 0
 namespace std
 {
 	/**
@@ -48,6 +50,7 @@ namespace std
 				                void **thrown_object) const;
 	};
 }
+#endif
 
 using namespace std;
 
