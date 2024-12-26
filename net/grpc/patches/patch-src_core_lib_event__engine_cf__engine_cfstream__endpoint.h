$NetBSD: patch-src_core_lib_event__engine_cf__engine_cfstream__endpoint.h,v 1.2 2024/12/26 23:48:22 adam Exp $

Fix error: no member named 'StrCat' in namespace 'absl'.

--- src/core/lib/event_engine/cf_engine/cfstream_endpoint.h.orig	2024-11-14 22:30:21.000000000 +0000
+++ src/core/lib/event_engine/cf_engine/cfstream_endpoint.h
@@ -22,6 +22,7 @@
 #include <CoreFoundation/CoreFoundation.h>
 #include <grpc/event_engine/event_engine.h>
 
+#include "absl/strings/str_cat.h"
 #include "absl/strings/str_format.h"
 #include "src/core/lib/address_utils/sockaddr_utils.h"
 #include "src/core/lib/event_engine/cf_engine/cf_engine.h"
