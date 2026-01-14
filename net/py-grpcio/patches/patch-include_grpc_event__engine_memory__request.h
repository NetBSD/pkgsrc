$NetBSD: patch-include_grpc_event__engine_memory__request.h,v 1.1 2026/01/14 17:20:16 ryoon Exp $

--- include/grpc/event_engine/memory_request.h.orig	2026-01-14 15:51:44.506266411 +0000
+++ include/grpc/event_engine/memory_request.h
@@ -16,6 +16,7 @@
 
 #include <grpc/support/port_platform.h>
 #include <stddef.h>
+#include <string>
 
 #include "absl/strings/string_view.h"
 
