$NetBSD: patch-bridges_source_cpp__uno_gcc3__linux__x86-64_share.hxx,v 1.1 2014/01/20 19:27:51 joerg Exp $

--- bridges/source/cpp_uno/gcc3_linux_x86-64/share.hxx.orig	2013-10-22 17:49:23.000000000 +0000
+++ bridges/source/cpp_uno/gcc3_linux_x86-64/share.hxx
@@ -19,6 +19,7 @@
 
 #include "uno/mapping.h"
 
+#include <cxxabi.h>
 #include <typeinfo>
 #include <exception>
 #include <cstddef>
@@ -28,6 +29,11 @@ namespace CPPU_CURRENT_NAMESPACE
 
 // ----- following decl from libstdc++-v3/libsupc++/unwind-cxx.h and unwind.h
 
+#ifdef _LIBCPP_VERSION
+using __cxxabiv1::__cxa_exception;
+using __cxxabiv1::__cxa_eh_globals;
+using ::_Unwind_Exception;
+#else
 struct _Unwind_Exception
 {
     unsigned exception_class __attribute__((__mode__(__DI__)));
@@ -62,9 +68,37 @@ struct __cxa_eh_globals
     __cxa_exception *caughtExceptions;
     unsigned int uncaughtExceptions;
 };
+#endif
+
+}
+
+#ifdef _LIBCPP_VERSION
+
+namespace __cxxabiv1
+{
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
 
+extern "C" void *__cxa_allocate_exception( std::size_t thrown_size ) _NOEXCEPT;
+
+extern "C" _LIBCPP_NORETURN void __cxa_throw(
+    void *thrown_exception, std::type_info *tinfo, void (*dest) (void *) );
 }
 
+using __cxxabiv1::__cxa_get_globals;
+
+#else
 extern "C" CPPU_CURRENT_NAMESPACE::__cxa_eh_globals *__cxa_get_globals () throw();
 
 namespace CPPU_CURRENT_NAMESPACE
@@ -81,9 +115,13 @@ extern "C" void *__cxa_allocate_exceptio
 extern "C" void __cxa_throw (
     void *thrown_exception, void *tinfo, void (*dest) (void *) ) __attribute__((noreturn));
 #endif
+}
+#endif
 
 // -----
 
+namespace CPPU_CURRENT_NAMESPACE
+{
 //==================================================================================================
 void raiseException(
     uno_Any * pUnoExc, uno_Mapping * pUno2Cpp );
