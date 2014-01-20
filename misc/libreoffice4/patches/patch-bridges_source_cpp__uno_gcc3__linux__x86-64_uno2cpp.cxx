$NetBSD: patch-bridges_source_cpp__uno_gcc3__linux__x86-64_uno2cpp.cxx,v 1.1 2014/01/20 19:27:51 joerg Exp $

--- bridges/source/cpp_uno/gcc3_linux_x86-64/uno2cpp.cxx.orig	2014-01-18 00:19:15.000000000 +0000
+++ bridges/source/cpp_uno/gcc3_linux_x86-64/uno2cpp.cxx
@@ -290,7 +290,7 @@ static void cpp_call(
      catch (...)
      {
           // fill uno exception
-        fillUnoException( __cxa_get_globals()->caughtExceptions, *ppUnoExc, pThis->getBridge()->getCpp2Uno() );
+        CPPU_CURRENT_NAMESPACE::fillUnoException( __cxa_get_globals()->caughtExceptions, *ppUnoExc, pThis->getBridge()->getCpp2Uno() );
 
         // temporary params
         for ( ; nTempIndizes--; )
