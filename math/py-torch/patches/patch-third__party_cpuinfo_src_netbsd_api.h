$NetBSD: patch-third__party_cpuinfo_src_netbsd_api.h,v 1.1 2025/01/21 13:36:49 ryoon Exp $

* Add NetBSD support.

--- third_party/cpuinfo/src/netbsd/api.h.orig	2025-01-17 16:33:50.739885970 +0000
+++ third_party/cpuinfo/src/netbsd/api.h
@@ -0,0 +1,12 @@
+#pragma once
+
+#include <stdint.h>
+
+struct cpuinfo_netbsd_topology {
+	uint32_t packages;
+	uint32_t cores;
+	uint32_t threads;
+	uint32_t threads_per_core;
+};
+
+struct cpuinfo_netbsd_topology cpuinfo_netbsd_detect_topology(void);
