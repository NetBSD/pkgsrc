$NetBSD: patch-src_utils_random__generator.hpp,v 1.2 2014/01/01 02:46:49 ryoon Exp $

--- src/utils/random_generator.hpp.orig	2013-11-15 11:43:21.000000000 +0000
+++ src/utils/random_generator.hpp
@@ -19,6 +19,7 @@
 #ifndef HEADER_RANDOM_GENERATOR_HPP
 #define HEADER_RANDOM_GENERATOR_HPP
 
+#include <cstdlib>
 #include <algorithm>
 #include <vector>
 #include <stdlib.h>
