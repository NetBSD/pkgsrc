$NetBSD: patch-plugin_x_tests_driver_connector_warning.h,v 1.1 2025/09/28 16:46:33 bsiegert Exp $

Fix Linux builds -- uint32_t needs to be defined

--- plugin/x/tests/driver/connector/warning.h.orig	2025-09-28 16:34:11.331862775 +0000
+++ plugin/x/tests/driver/connector/warning.h
@@ -26,6 +26,7 @@
 #ifndef PLUGIN_X_TESTS_DRIVER_CONNECTOR_WARNING_H_
 #define PLUGIN_X_TESTS_DRIVER_CONNECTOR_WARNING_H_
 
+#include <cstdint>
 #include <memory>
 #include <ostream>
 #include <string>
