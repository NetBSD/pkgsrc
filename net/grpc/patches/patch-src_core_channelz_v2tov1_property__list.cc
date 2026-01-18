$NetBSD: patch-src_core_channelz_v2tov1_property__list.cc,v 1.1 2026/01/18 10:43:48 wiz Exp $

error: 'numeric_limits' is not a member of 'std'
https://github.com/grpc/grpc/commit/d54219b508423f0a2ff6a0b98c16fb6dafd44b84

--- src/core/channelz/v2tov1/property_list.cc.orig	2026-01-18 10:07:31.004738891 +0000
+++ src/core/channelz/v2tov1/property_list.cc
@@ -15,6 +15,7 @@
 #include "src/core/channelz/v2tov1/property_list.h"
 
 #include <cstdint>
+#include <limits>
 #include <optional>
 #include <string>
 
