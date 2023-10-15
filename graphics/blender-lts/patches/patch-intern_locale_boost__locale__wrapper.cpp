$NetBSD: patch-intern_locale_boost__locale__wrapper.cpp,v 1.2 2023/10/15 19:55:00 ryoon Exp $

Add missing header for std::cout.

--- intern/locale/boost_locale_wrapper.cpp.orig	2023-06-15 13:23:28.000000000 +0000
+++ intern/locale/boost_locale_wrapper.cpp
@@ -8,6 +8,7 @@
 #include <boost/locale.hpp>
 #include <iostream>
 #include <stdio.h>
+#include <iostream>
 
 #include "boost_locale_wrapper.h"
 
