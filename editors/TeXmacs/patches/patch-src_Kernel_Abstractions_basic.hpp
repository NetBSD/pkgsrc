$NetBSD: patch-src_Kernel_Abstractions_basic.hpp,v 1.1 2012/11/16 20:09:47 joerg Exp $

--- src/Kernel/Abstractions/basic.hpp.orig	2012-11-16 12:54:48.000000000 +0000
+++ src/Kernel/Abstractions/basic.hpp
@@ -69,7 +69,7 @@ void  operator delete[] (register void* 
 int   mem_used ();
 void  mem_info ();
 
-#if (defined OS_WIN32 || defined __SUNPRO_CC)
+#if (defined OS_WIN32 || defined __SUNPRO_CC) || defined(__clang__)
 #define STACK_NEW_ARRAY(name,T,size) T* name= new T[size]
 #define STACK_DELETE_ARRAY(name) delete[] name
 #else
