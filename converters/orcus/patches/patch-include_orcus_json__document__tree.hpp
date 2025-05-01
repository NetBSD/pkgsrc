$NetBSD: patch-include_orcus_json__document__tree.hpp,v 1.1 2025/05/01 21:39:20 tnn Exp $

https://gitlab.com/orcus/orcus/-/commit/b7932facdf56994b7b1238bafe1e13b4817f69f1.patch

--- include/orcus/json_document_tree.hpp.orig	2022-12-17 15:37:19.000000000 +0000
+++ include/orcus/json_document_tree.hpp
@@ -14,6 +14,7 @@
 #include <string>
 #include <memory>
 #include <vector>
+#include <cstdint>
 
 namespace orcus {
 
