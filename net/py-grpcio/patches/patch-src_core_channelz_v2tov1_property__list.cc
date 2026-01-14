$NetBSD: patch-src_core_channelz_v2tov1_property__list.cc,v 1.1 2026/01/14 17:20:16 ryoon Exp $

--- src/core/channelz/v2tov1/property_list.cc.orig	2026-01-14 16:02:01.545848676 +0000
+++ src/core/channelz/v2tov1/property_list.cc
@@ -17,6 +17,7 @@
 #include <cstdint>
 #include <optional>
 #include <string>
+#include <limits>
 
 #include "absl/strings/string_view.h"
 #include "google/protobuf/any.upb.h"
