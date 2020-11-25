$NetBSD: patch-server_pse_pse__netbsd.go,v 1.1 2020/11/25 16:55:47 otis Exp $

Implement NetBSD specific functions.

--- server/pse/pse_netbsd.go.orig	2020-10-12 21:03:54.012750981 +0000
+++ server/pse/pse_netbsd.go
@@ -0,0 +1,88 @@
+// +build netbsd
+// Copyright 2015-2018 The NATS Authors
+// Licensed under the Apache License, Version 2.0 (the "License");
+// you may not use this file except in compliance with the License.
+// You may obtain a copy of the License at
+//
+// http://www.apache.org/licenses/LICENSE-2.0
+//
+// Unless required by applicable law or agreed to in writing, software
+// distributed under the License is distributed on an "AS IS" BASIS,
+// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
+// See the License for the specific language governing permissions and
+// limitations under the License.
+//
+// NetBSD support (c) 2020 Juraj Lutter <otis@NetBSD.org>
+
+package pse
+
+/*
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <errno.h>
+#include <stddef.h>
+#include <unistd.h>
+
+long pagetok(long size)
+{
+    int pageshift, pagesize;
+
+    pagesize = getpagesize();
+    pageshift = 0;
+
+    while (pagesize > 1) {
+        pageshift++;
+        pagesize >>= 1;
+    }
+
+    return (size << pageshift);
+}
+
+int getusage(double *pcpu, unsigned int *rss, unsigned int *vss)
+{
+    int mib[6], ret;
+    size_t len;
+    struct kinfo_proc2 kp;
+
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_PROC2;
+    mib[2] = KERN_PROC_PID;
+    mib[3] = getpid();
+    mib[4] = sizeof(kp);
+    mib[5] = 1;
+
+    len = sizeof(kp);
+    ret = sysctl(mib, 6, &kp, &len, NULL, 0);
+    if (ret != 0) {
+        return (errno);
+    }
+
+    *rss = pagetok(kp.p_vm_rssize);
+    *vss = kp.p_vm_vsize;
+    *pcpu = kp.p_pctcpu;
+
+    return 0;
+}
+
+*/
+import "C"
+
+import (
+	"syscall"
+)
+
+// This is a placeholder for now.
+func ProcUsage(pcpu *float64, rss, vss *int64) error {
+	var r, v C.uint
+	var c C.double
+
+	if ret := C.getusage(&c, &r, &v); ret != 0 {
+		return syscall.Errno(ret)
+	}
+
+	*pcpu = float64(c)
+	*rss = int64(r)
+	*vss = int64(v)
+
+	return nil
+}
