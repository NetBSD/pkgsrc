$NetBSD: patch-bridges_source_cpp__uno_gcc3__linux__intel_uno2cpp.cxx,v 1.3 2014/06/01 14:31:08 ryoon Exp $

--- bridges/source/cpp_uno/gcc3_linux_intel/uno2cpp.cxx.orig	2014-04-30 19:49:45.000000000 +0000
+++ bridges/source/cpp_uno/gcc3_linux_intel/uno2cpp.cxx
@@ -203,7 +203,11 @@ static void cpp_call(
      catch (...)
      {
           // fill uno exception
+#ifdef _LIBCPP_VERSION
+        CPPU_CURRENT_NAMESPACE::fillUnoException( __cxxabiv1::__cxa_get_globals()->caughtExceptions, *ppUnoExc, pThis->getBridge()->getCpp2Uno() );
+#else
         fillUnoException( __cxa_get_globals()->caughtExceptions, *ppUnoExc, pThis->getBridge()->getCpp2Uno() );
+#endif
 
         // temporary params
         for ( ; nTempIndices--; )
