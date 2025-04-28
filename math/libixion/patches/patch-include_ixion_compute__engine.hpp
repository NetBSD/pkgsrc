$NetBSD: patch-include_ixion_compute__engine.hpp,v 1.1 2025/04/28 21:04:38 tnn Exp $

Add a missing <cstdint> include: https://gitlab.com/ixion/ixion/-/commit/cb662d675aaa419972d39c5606713919e3e1d6f9

--- include/ixion/compute_engine.hpp.orig	2025-04-28 21:01:15.683708584 +0000
+++ include/ixion/compute_engine.hpp
@@ -13,6 +13,7 @@
 
 #include <memory>
 #include <string>
+#include <cstdint>
 
 namespace ixion { namespace draft {
 
