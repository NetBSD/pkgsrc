$NetBSD: patch-src_utils_random__generator.hpp,v 1.1 2013/06/26 21:23:52 joerg Exp $

--- src/utils/random_generator.hpp.orig	2013-06-26 20:47:27.000000000 +0000
+++ src/utils/random_generator.hpp
@@ -19,6 +19,7 @@
 #ifndef HEADER_RANDOM_GENERATOR_HPP
 #define HEADER_RANDOM_GENERATOR_HPP
 
+#include <cstdlib>
 #include <algorithm>
 #include <vector>
 
