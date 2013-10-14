$NetBSD: patch-include_ptlib_object.h,v 1.1 2013/10/14 14:36:12 joerg Exp $

--- include/ptlib/object.h.orig	2013-10-14 12:44:10.000000000 +0000
+++ include/ptlib/object.h
@@ -1011,7 +1011,7 @@ struct PAllocatorTemplate
                    + __GNUC_PATCHLEVEL__)
 
 // Memory pooling allocators
-#if defined(__GNUC__) && (GCC_VERSION > 40000) && !defined(P_MINGW) && !defined(P_MACOSX) 
+#if defined(__GNUC__) && (GCC_VERSION > 40000) && !defined(P_MINGW) && !defined(P_MACOSX) && !defined(_LIBCPP_VERSION)
 #include <ext/mt_allocator.h>
 template <class Type> struct PFixedPoolAllocator    : public PAllocatorTemplate<__gnu_cxx::__mt_alloc<Type>, Type> { };
 template <class Type> struct PVariablePoolAllocator : public PAllocatorTemplate<__gnu_cxx::__mt_alloc<Type>, Type> { };
