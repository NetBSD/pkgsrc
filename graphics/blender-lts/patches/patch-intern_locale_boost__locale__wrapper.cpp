$NetBSD: patch-intern_locale_boost__locale__wrapper.cpp,v 1.1 2023/04/25 15:59:02 wiz Exp $

Add missing header for std::cout.

--- intern/locale/boost_locale_wrapper.cpp.orig	2020-07-22 12:23:09.000000000 +0000
+++ intern/locale/boost_locale_wrapper.cpp
@@ -19,6 +19,7 @@
 
 #include <boost/locale.hpp>
 #include <stdio.h>
+#include <iostream>
 
 #include "boost_locale_wrapper.h"
 
