$NetBSD: patch-bridges_source_cpp__uno_gcc3__linux__x86-64_uno2cpp.cxx,v 1.3 2014/02/21 20:29:52 joerg Exp $

--- bridges/source/cpp_uno/gcc3_linux_x86-64/uno2cpp.cxx.orig	2014-01-27 21:35:34.000000000 +0000
+++ bridges/source/cpp_uno/gcc3_linux_x86-64/uno2cpp.cxx
@@ -290,7 +290,7 @@ static void cpp_call(
      catch (...)
      {
          // fill uno exception
-         fillUnoException(
+         CPPU_CURRENT_NAMESPACE::fillUnoException(
              reinterpret_cast< CPPU_CURRENT_NAMESPACE::__cxa_eh_globals * >(
                  __cxxabiv1::__cxa_get_globals())->caughtExceptions,
              *ppUnoExc, pThis->getBridge()->getCpp2Uno());
