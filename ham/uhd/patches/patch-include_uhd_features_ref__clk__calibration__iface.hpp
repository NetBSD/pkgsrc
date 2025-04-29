$NetBSD: patch-include_uhd_features_ref__clk__calibration__iface.hpp,v 1.1 2025/04/29 09:17:25 tnn Exp $

https://github.com/EttusResearch/uhd/commit/14337e23e4e073be5377dbcefc96ed04515ac51a.patch

--- include/uhd/features/ref_clk_calibration_iface.hpp.orig	2025-01-27 14:59:07.000000000 +0000
+++ include/uhd/features/ref_clk_calibration_iface.hpp
@@ -8,6 +8,7 @@
 
 #include <uhd/config.hpp>
 #include <uhd/features/discoverable_feature.hpp>
+#include <cstdint>
 #include <memory>
 
 namespace uhd { namespace features {
