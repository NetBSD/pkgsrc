$NetBSD: patch-bridges_source_cpp__uno_gcc3__linux__intel_except.cxx,v 1.1 2014/06/01 14:31:08 ryoon Exp $

--- bridges/source/cpp_uno/gcc3_linux_intel/except.cxx.orig	2014-04-30 19:49:45.000000000 +0000
+++ bridges/source/cpp_uno/gcc3_linux_intel/except.cxx
@@ -22,11 +22,6 @@
 #include <dlfcn.h>
 #include <boost/unordered_map.hpp>
 
-#include <cxxabi.h>
-#ifndef _GLIBCXX_CDTOR_CALLABI // new in GCC 4.7 cxxabi.h
-#define _GLIBCXX_CDTOR_CALLABI
-#endif
-
 #include <rtl/strbuf.hxx>
 #include <rtl/ustrbuf.hxx>
 #include <osl/diagnose.h>
@@ -248,7 +243,11 @@ void raiseException( uno_Any * pUnoExc, 
             Reference< XInterface >() );
     }
 
+#ifdef _LIBCPP_VERSION
+    pCppExc = __cxxabiv1::__cxa_allocate_exception( pTypeDescr->nSize );
+#else
     pCppExc = __cxa_allocate_exception( pTypeDescr->nSize );
+#endif
     ::uno_copyAndConvertData( pCppExc, pUnoExc->pData, pTypeDescr, pUno2Cpp );
 
     // destruct uno exception
@@ -280,7 +279,11 @@ void raiseException( uno_Any * pUnoExc, 
     }
     }
 
+#ifdef _LIBCPP_VERSION
+    __cxxabiv1::__cxa_throw( pCppExc, rtti, deleteException );
+#else
     __cxa_throw( pCppExc, rtti, deleteException );
+#endif
 }
 
 //==================================================================================================
