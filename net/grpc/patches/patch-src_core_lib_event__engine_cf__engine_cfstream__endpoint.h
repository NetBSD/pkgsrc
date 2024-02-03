$NetBSD: patch-src_core_lib_event__engine_cf__engine_cfstream__endpoint.h,v 1.1 2024/02/03 20:02:03 adam Exp $

Fix error: no member named 'StrCat' in namespace 'absl'.

--- src/core/lib/event_engine/cf_engine/cfstream_endpoint.h.orig	2024-02-03 19:48:36.455664126 +0000
+++ src/core/lib/event_engine/cf_engine/cfstream_endpoint.h
@@ -21,6 +21,7 @@
 
 #include <CoreFoundation/CoreFoundation.h>
 
+#include "absl/strings/str_cat.h"
 #include "absl/strings/str_format.h"
 
 #include <grpc/event_engine/event_engine.h>
