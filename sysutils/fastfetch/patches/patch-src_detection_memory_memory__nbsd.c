$NetBSD: patch-src_detection_memory_memory__nbsd.c,v 1.1 2025/01/12 11:07:38 vins Exp $

Memory detection for NetBSD.

--- src/detection/memory/memory_nbsd.c.orig	2025-01-12 09:48:00.475080521 +0000
+++ src/detection/memory/memory_nbsd.c
@@ -0,0 +1,19 @@
+#include "memory.h"
+#include "common/sysctl.h"
+
+#include <sys/param.h>
+#include <uvm/uvm_extern.h>
+
+const char* ffDetectMemory(FFMemoryResult* ram)
+{
+    static int uvmexp_mib[] = {CTL_VM, VM_UVMEXP2};
+    struct uvmexp_sysctl buf;
+    size_t length = sizeof(buf);
+    if (sysctl(uvmexp_mib, 2, &buf, &length, NULL, 0) < 0)
+	return "sysctl(CTL_VM, VM_UVMEXP2) call failed";
+
+    ram->bytesTotal = (uint64_t) buf.npages * instance.state.platform.sysinfo.pageSize;
+    ram->bytesUsed = ((uint64_t) buf.active + (uint64_t) buf.wired) * instance.state.platform.sysinfo.pageSize;
+
+    return NULL;
+}
