$NetBSD: patch-boost_core_uncaught__exceptions.hpp,v 1.1 2019/08/22 21:05:27 tnn Exp $

match prototype for __cxa_get_globals() from libc++

./boost/core/uncaught_exceptions.hpp:75:30: error: exception specification in declaration does not match previous declaration
/usr/include/c++/cxxabi.h:190:19: note: previous declaration is here
__cxa_eh_globals *__cxa_get_globals(void);

--- boost/core/uncaught_exceptions.hpp.orig	2019-08-22 20:44:08.783902992 +0000
+++ boost/core/uncaught_exceptions.hpp
@@ -69,7 +69,7 @@
     )
 namespace __cxxabiv1 {
 struct __cxa_eh_globals;
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || (defined(__NetBSD__) && defined(_LIBCPP_VERSION))
 extern "C" __cxa_eh_globals* __cxa_get_globals();
 #else
 extern "C" __cxa_eh_globals* __cxa_get_globals() BOOST_NOEXCEPT_OR_NOTHROW __attribute__((__const__));
