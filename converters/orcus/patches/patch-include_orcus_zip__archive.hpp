$NetBSD: patch-include_orcus_zip__archive.hpp,v 1.1 2025/05/01 21:39:20 tnn Exp $

https://gitlab.com/orcus/orcus/-/commit/b7932facdf56994b7b1238bafe1e13b4817f69f1.patch

--- include/orcus/zip_archive.hpp.orig	2023-02-09 03:08:15.000000000 +0000
+++ include/orcus/zip_archive.hpp
@@ -15,6 +15,7 @@
 #include <vector>
 #include <memory>
 #include <ostream>
+#include <cstdint>
 
 namespace orcus {
 
