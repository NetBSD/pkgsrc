$NetBSD: patch-bridges_source_cpp__uno_gcc3__linux__intel_uno2cpp.cxx,v 1.1 2014/02/21 20:29:52 joerg Exp $

--- bridges/source/cpp_uno/gcc3_linux_intel/uno2cpp.cxx.orig	2014-01-27 21:35:34.000000000 +0000
+++ bridges/source/cpp_uno/gcc3_linux_intel/uno2cpp.cxx
@@ -203,7 +203,7 @@ static void cpp_call(
      catch (...)
      {
           // fill uno exception
-        fillUnoException( __cxa_get_globals()->caughtExceptions, *ppUnoExc, pThis->getBridge()->getCpp2Uno() );
+        CPPU_CURRENT_NAMESPACE::fillUnoException( __cxa_get_globals()->caughtExceptions, *ppUnoExc, pThis->getBridge()->getCpp2Uno() );
 
         // temporary params
         for ( ; nTempIndices--; )
