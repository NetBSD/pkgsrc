$NetBSD: patch-bridges_source_cpp__uno_gcc3__linux__intel_share.hxx,v 1.5 2014/06/01 14:31:08 ryoon Exp $

--- bridges/source/cpp_uno/gcc3_linux_intel/share.hxx.orig	2014-04-30 19:49:45.000000000 +0000
+++ bridges/source/cpp_uno/gcc3_linux_intel/share.hxx
@@ -25,10 +25,39 @@
 
 #include <uno/any2.h>
 
-namespace CPPU_CURRENT_NAMESPACE
+#include <cxxabi.h>
+#ifndef _GLIBCXX_CDTOR_CALLABI // new in GCC 4.7 cxxabi.h
+#define _GLIBCXX_CDTOR_CALLABI
+#endif
+
+#ifdef _LIBCPP_VERSION
+
+namespace __cxxabiv1
 {
+    struct __class_type_info : public std::type_info
+    {
+        explicit __class_type_info( const char *__n ) : type_info( __n ) { }
+        virtual ~__class_type_info();
+    };
+
+    struct __si_class_type_info : public __class_type_info
+    {
+        explicit __si_class_type_info( const char *__n, const __class_type_info *__b ) :
+            __class_type_info( __n ), __base_type( __b ) { }
+        virtual ~__si_class_type_info();
+        const __class_type_info *__base_type;
+    };
 
-void dummy_can_throw_anything( char const * );
+extern "C" void *__cxa_allocate_exception( std::size_t thrown_size ) _NOEXCEPT;
+
+extern "C" _LIBCPP_NORETURN void __cxa_throw(
+    void *thrown_exception, std::type_info *tinfo, void (*dest) (void *) );
+}
+
+#else
+
+namespace CPPU_CURRENT_NAMESPACE
+{
 
 // ----- following decl from libstdc++-v3/libsupc++/unwind-cxx.h and unwind.h
 
@@ -86,6 +115,15 @@ extern "C" void __cxa_throw (
     void *thrown_exception, void *tinfo, void (*dest) (void *) ) __attribute__((noreturn));
 #endif
 
+}
+
+#endif
+
+namespace CPPU_CURRENT_NAMESPACE
+{
+
+void dummy_can_throw_anything( char const * );
+
 // -----
 
 //==================================================================================================
@@ -93,8 +131,11 @@ void raiseException(
     uno_Any * pUnoExc, uno_Mapping * pUno2Cpp );
 //==================================================================================================
 void fillUnoException(
+#ifdef _LIBCPP_VERSION
+    __cxxabiv1::__cxa_exception * header, uno_Any *, uno_Mapping * pCpp2Uno );
+#else
     __cxa_exception * header, uno_Any *, uno_Mapping * pCpp2Uno );
-
+#endif
 }
 
 namespace x86
