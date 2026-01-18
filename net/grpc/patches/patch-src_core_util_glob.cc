$NetBSD: patch-src_core_util_glob.cc,v 1.1 2026/01/18 10:43:48 wiz Exp $

error: 'any_of' is not a member of 'std'
https://github.com/grpc/grpc/commit/d54219b508423f0a2ff6a0b98c16fb6dafd44b84

--- src/core/util/glob.cc.orig	2026-01-18 10:34:03.246212449 +0000
+++ src/core/util/glob.cc
@@ -13,6 +13,7 @@
 // limitations under the License.
 
 #include "absl/strings/string_view.h"
+#include <algorithm>
 
 namespace grpc_core {
 
