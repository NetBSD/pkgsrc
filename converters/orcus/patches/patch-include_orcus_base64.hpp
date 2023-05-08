$NetBSD: patch-include_orcus_base64.hpp,v 1.1 2023/05/08 18:28:03 tnn Exp $

Complains about missing uint8_t on Fedora 38 (GCC 13)

--- include/orcus/base64.hpp.orig	2021-10-14 02:59:58.000000000 +0000
+++ include/orcus/base64.hpp
@@ -11,6 +11,7 @@
 #include "env.hpp"
 #include <vector>
 #include <string>
+#include <cstdint>
 
 namespace orcus {
 
