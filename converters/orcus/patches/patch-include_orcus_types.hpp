$NetBSD: patch-include_orcus_types.hpp,v 1.1 2023/05/08 18:28:03 tnn Exp $

Complains about missing uint8_t on Fedora 38 (GCC 13)

--- include/orcus/types.hpp.orig	2021-11-19 01:48:15.000000000 +0000
+++ include/orcus/types.hpp
@@ -8,6 +8,7 @@
 #ifndef INCLUDED_ORCUS_TYPES_HPP
 #define INCLUDED_ORCUS_TYPES_HPP
 
+#include <cstdint>
 #include <cstdlib>
 #include <vector>
 #include <string>
