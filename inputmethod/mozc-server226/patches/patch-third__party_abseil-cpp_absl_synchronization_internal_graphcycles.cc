$NetBSD: patch-third__party_abseil-cpp_absl_synchronization_internal_graphcycles.cc,v 1.1 2026/04/06 14:15:18 tsutsui Exp $

Fix build errors on NetBSD/i386 11.0_RC3 with gcc12

--- third_party/abseil-cpp/absl/synchronization/internal/graphcycles.cc.orig	2026-04-06 10:15:08.606570125 +0000
+++ third_party/abseil-cpp/absl/synchronization/internal/graphcycles.cc
@@ -37,6 +37,7 @@
 
 #include <algorithm>
 #include <array>
+#include <limits>
 #include "absl/base/internal/hide_ptr.h"
 #include "absl/base/internal/raw_logging.h"
 #include "absl/base/internal/spinlock.h"
