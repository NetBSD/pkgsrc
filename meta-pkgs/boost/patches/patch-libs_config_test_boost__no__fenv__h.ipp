$NetBSD: patch-libs_config_test_boost__no__fenv__h.ipp,v 1.1 2011/10/02 10:20:28 sbd Exp $

The fenv.h test normaly fails with:
./../../libs/config/test/boost_no_fenv_h.ipp: In function 'int boost_no_fenv_h::test()':
./../../libs/config/test/boost_no_fenv_h.ipp:67:49: error: invalid conversion from 'int (*)()throw ()' to 'int (*)(fexcept_t*, int)'

This causes BOOST_NO_FENV_H to be set (breaking boost-libs).

--- libs/config/test/boost_no_fenv_h.ipp.orig	2010-12-31 17:08:07.000000000 +0000
+++ libs/config/test/boost_no_fenv_h.ipp
@@ -61,7 +61,11 @@ int test()
 
   int (*has_feclearexcept)(int) = ::feclearexcept;
   int (*has_fegetenv)(fenv_t*) = ::fegetenv;
-  int (*has_fegetexcept)(fexcept_t*, int) = ::fegetexcept;
+  #ifdef __linux__
+    int (*has_fegetexcept)(void) = ::fegetexcept;
+  #else
+    int (*has_fegetexcept)(fexcept_t*, int) = ::fegetexcept;
+  #endif
   int (*has_fegetround)(void) = ::fegetround;
   int (*has_feholdexcept)(fenv_t*) = ::feholdexcept;
   int (*has_feraiseexcept)(int) = ::feraiseexcept;
