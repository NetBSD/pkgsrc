$NetBSD: patch-third__party_cpuinfo_src_netbsd_topology.c,v 1.1 2025/01/21 13:36:49 ryoon Exp $

* Add preliminary NetBSD support. This is incorrect anyway.

--- third_party/cpuinfo/src/netbsd/topology.c.orig	2025-01-17 16:33:50.739896420 +0000
+++ third_party/cpuinfo/src/netbsd/topology.c
@@ -0,0 +1,74 @@
+#include <errno.h>
+#include <stdlib.h>
+#include <string.h>
+
+#include <sys/sysctl.h>
+#include <sys/types.h>
+
+#include <cpuinfo/log.h>
+#include <netbsd/api.h>
+
+static int sysctl_int(const char* name) {
+	int value = 0;
+	size_t value_size = sizeof(value);
+	if (sysctlbyname(name, &value, &value_size, NULL, 0) != 0) {
+		cpuinfo_log_error("sysctlbyname(\"%s\") failed: %s", name, strerror(errno));
+	} else if (value <= 0) {
+		cpuinfo_log_error("sysctlbyname(\"%s\") returned invalid value %d %zu", name, value, value_size);
+		value = 0;
+	}
+	return value;
+}
+
+static char* sysctl_str(const char* name) {
+	size_t value_size = 0;
+	if (sysctlbyname(name, NULL, &value_size, NULL, 0) != 0) {
+		cpuinfo_log_error("sysctlbyname(\"%s\") failed: %s", name, strerror(errno));
+		return NULL;
+	} else if (value_size <= 0) {
+		cpuinfo_log_error("sysctlbyname(\"%s\") returned invalid value size %zu", name, value_size);
+		return NULL;
+	}
+	value_size += 1;
+	char* value = calloc(value_size, 1);
+	if (!value) {
+		cpuinfo_log_error("calloc %zu bytes failed", value_size);
+		return NULL;
+	}
+	if (sysctlbyname(name, value, &value_size, NULL, 0) != 0) {
+		cpuinfo_log_error("sysctlbyname(\"%s\") failed: %s", name, strerror(errno));
+		free(value);
+		return NULL;
+	}
+	return value;
+}
+
+struct cpuinfo_netbsd_topology cpuinfo_netbsd_detect_topology(void) {
+	struct cpuinfo_netbsd_topology topology = {
+		.packages = 0,
+		.cores = 0,
+		.threads_per_core = 0,
+		.threads = 0,
+	};
+	topology.packages = 1;
+	topology.cores = sysctl_int("hw.ncpu");
+	if (topology.cores == 0) {
+		goto fail;
+	}
+	if (topology.cores < topology.packages) {
+		cpuinfo_log_error("invalid numbers of package and core: %d %d", topology.packages, topology.cores);
+		goto fail;
+	}
+	topology.threads_per_core = 1;
+	cpuinfo_log_debug(
+		"netbsd topology: packages = %d, cores = %d, "
+		"threads_per_core = %d",
+		topology.packages,
+		topology.cores,
+		topology.threads_per_core);
+	topology.threads = topology.threads_per_core * topology.cores;
+	return topology;
+fail:
+	topology.packages = 0;
+	return topology;
+}
