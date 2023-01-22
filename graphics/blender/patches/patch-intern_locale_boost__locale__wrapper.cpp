$NetBSD: patch-intern_locale_boost__locale__wrapper.cpp,v 1.1 2023/01/22 21:24:37 ryoon Exp $

--- intern/locale/boost_locale_wrapper.cpp.orig	2022-11-04 00:33:06.000000000 +0000
+++ intern/locale/boost_locale_wrapper.cpp
@@ -5,6 +5,7 @@
  * \ingroup intern_locale
  */
 
+#include <iostream>
 #include <boost/locale.hpp>
 #include <stdio.h>
 
