$NetBSD: patch-include_orcus_sax__parser.hpp,v 1.1 2025/05/01 21:39:20 tnn Exp $

https://gitlab.com/orcus/orcus/-/commit/b7932facdf56994b7b1238bafe1e13b4817f69f1.patch

--- include/orcus/sax_parser.hpp.orig	2023-02-08 00:49:51.000000000 +0000
+++ include/orcus/sax_parser.hpp
@@ -11,6 +11,7 @@
 #include "sax_parser_base.hpp"
 
 #include <string_view>
+#include <cstdint>
 
 namespace orcus {
 
