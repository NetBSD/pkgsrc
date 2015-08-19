$NetBSD: patch-bridges_source_cpp__uno_gcc3__linux__x86-64_uno2cpp.cxx,v 1.1 2015/08/19 07:11:44 he Exp $

--- bridges/source/cpp_uno/gcc3_linux_x86-64/uno2cpp.cxx.orig	2014-04-30 19:49:45.000000000 +0000
+++ bridges/source/cpp_uno/gcc3_linux_x86-64/uno2cpp.cxx
@@ -290,10 +290,14 @@ static void cpp_call(
      catch (...)
      {
          // fill uno exception
+#ifdef _LIBCPP_VERSION
+        CPPU_CURRENT_NAMESPACE::fillUnoException( __cxxabiv1::__cxa_get_globals()->caughtExceptions, *ppUnoExc, pThis->getBridge()->getCpp2Uno() );
+#else
          fillUnoException(
              reinterpret_cast< CPPU_CURRENT_NAMESPACE::__cxa_eh_globals * >(
                  __cxxabiv1::__cxa_get_globals())->caughtExceptions,
              *ppUnoExc, pThis->getBridge()->getCpp2Uno());
+#endif
 
         // temporary params
         for ( ; nTempIndices--; )
