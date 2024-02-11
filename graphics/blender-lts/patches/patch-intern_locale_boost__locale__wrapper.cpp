$NetBSD: patch-intern_locale_boost__locale__wrapper.cpp,v 1.3 2024/02/11 15:29:59 ryoon Exp $

--- intern/locale/boost_locale_wrapper.cpp.orig	2023-02-15 22:58:23.000000000 +0000
+++ intern/locale/boost_locale_wrapper.cpp
@@ -5,6 +5,7 @@
  * \ingroup intern_locale
  */
 
+#include <iostream>
 #include <boost/locale.hpp>
 #include <iostream>
 #include <stdio.h>
