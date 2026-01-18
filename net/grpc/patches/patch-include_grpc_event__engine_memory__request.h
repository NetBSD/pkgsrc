$NetBSD: patch-include_grpc_event__engine_memory__request.h,v 1.1 2026/01/18 10:43:48 wiz Exp $

error: 'to_string' is not a member of 'std'
https://github.com/grpc/grpc/commit/d54219b508423f0a2ff6a0b98c16fb6dafd44b84

--- include/grpc/event_engine/memory_request.h.orig	2026-01-18 10:15:33.124706419 +0000
+++ include/grpc/event_engine/memory_request.h
@@ -16,6 +16,7 @@
 
 #include <grpc/support/port_platform.h>
 #include <stddef.h>
+#include <string>
 
 #include "absl/strings/string_view.h"
 
