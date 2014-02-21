$NetBSD: patch-bridges_source_cpp__uno_gcc3__linux__x86-64_share.hxx,v 1.3 2014/02/21 20:29:52 joerg Exp $

--- bridges/source/cpp_uno/gcc3_linux_x86-64/share.hxx.orig	2014-01-27 21:35:34.000000000 +0000
+++ bridges/source/cpp_uno/gcc3_linux_x86-64/share.hxx
@@ -19,6 +19,7 @@
 
 #include "sal/config.h"
 
+#include <cxxabi.h>
 #include <typeinfo>
 #include <exception>
 #include <cstddef>
@@ -31,11 +32,36 @@
 #include "config_gcc.h"
 #include "uno/mapping.h"
 
-namespace CPPU_CURRENT_NAMESPACE
+// ----- following decl from libstdc++-v3/libsupc++/unwind-cxx.h and unwind.h
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
+}
 
-// ----- following decl from libstdc++-v3/libsupc++/unwind-cxx.h and unwind.h
+#endif
+
+namespace CPPU_CURRENT_NAMESPACE
+{
 
+#ifdef _LIBCPP_VERSION
+using __cxxabiv1::__cxa_exception;
+using __cxxabiv1::__cxa_eh_globals;
+using ::_Unwind_Exception;
+#else
 struct _Unwind_Exception
 {
     unsigned exception_class __attribute__((__mode__(__DI__)));
@@ -70,7 +96,7 @@ struct __cxa_eh_globals
     __cxa_exception *caughtExceptions;
     unsigned int uncaughtExceptions;
 };
-
+#endif
 }
 
 // __cxa_get_globals is exported from libstdc++ since GCC 3.4.0 (CXXABI_1.3),
