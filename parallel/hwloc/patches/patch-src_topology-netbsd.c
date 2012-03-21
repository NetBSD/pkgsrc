$NetBSD: patch-src_topology-netbsd.c,v 1.1.1.1 2012/03/21 13:31:35 asau Exp $

--- src/topology-netbsd.c.orig	2012-03-21 11:13:38.000000000 +0000
+++ src/topology-netbsd.c
@@ -0,0 +1,166 @@
+/*
+ * Copyright © 2012 Aleksej Saushev, The NetBSD Foundation
+ * Copyright © 2009-2011 inria.  All rights reserved.
+ * Copyright © 2009-2010 Université Bordeaux 1
+ * Copyright © 2011 Cisco Systems, Inc.  All rights reserved.
+ * See COPYING in top-level directory.
+ */
+
+#define _NETBSD_SOURCE /* request "_np" functions */
+
+#include <private/autogen/config.h>
+
+#include <sys/types.h>
+#include <stdlib.h>
+#include <inttypes.h>
+#include <sys/param.h>
+#include <pthread.h>
+#include <sched.h>
+
+#include <hwloc.h>
+#include <private/private.h>
+#include <private/debug.h>
+
+/* #ifdef HAVE_SCHED_H */
+static void
+hwloc_netbsd_bsd2hwloc(hwloc_bitmap_t hwloc_cpuset, const cpuset_t *cpuset)
+{
+  unsigned cpu, cpulimit;
+  hwloc_bitmap_zero(hwloc_cpuset);
+  cpulimit = cpuset_size(cpuset) * CHAR_BIT;
+  for (cpu = 0; cpu < cpulimit; cpu++)
+    if (cpuset_isset(cpu, cpuset))
+      hwloc_bitmap_set(hwloc_cpuset, cpu);
+}
+
+static void
+hwloc_netbsd_hwloc2bsd(hwloc_const_bitmap_t hwloc_cpuset, cpuset_t *cpuset)
+{
+  unsigned cpu, cpulimit;
+  cpuset_zero(cpuset);
+  cpulimit = cpuset_size(cpuset) * CHAR_BIT;
+  for (cpu = 0; cpu < cpulimit; cpu++)
+    if (hwloc_bitmap_isset(hwloc_cpuset, cpu))
+      cpuset_set(cpu, cpuset);
+}
+
+static int
+hwloc_netbsd_set_proc_cpubind(hwloc_topology_t topology __hwloc_attribute_unused, hwloc_pid_t pid, hwloc_const_bitmap_t hwloc_cpuset, int flags __hwloc_attribute_unused)
+{
+  int status;
+  cpuset_t *cpuset = cpuset_create();
+
+  hwloc_netbsd_hwloc2bsd(hwloc_cpuset, cpuset);
+
+  status = sched_setaffinity_np(pid, cpuset_size(cpuset), cpuset);
+
+  cpuset_destroy(cpuset);
+  return status;
+}
+
+static int
+hwloc_netbsd_get_proc_cpubind(hwloc_topology_t topology __hwloc_attribute_unused, hwloc_pid_t pid, hwloc_bitmap_t hwloc_cpuset, int flags __hwloc_attribute_unused)
+{
+  int status;
+  cpuset_t *cpuset = cpuset_create();
+
+  status = sched_setaffinity_np(pid, cpuset_size(cpuset), cpuset);
+  hwloc_netbsd_bsd2hwloc(hwloc_cpuset, cpuset);
+
+  cpuset_destroy(cpuset);
+  return status;
+}
+
+
+static int
+hwloc_netbsd_set_thisproc_cpubind(hwloc_topology_t topology, hwloc_const_bitmap_t hwloc_cpuset, int flags)
+{
+  return hwloc_netbsd_set_proc_cpubind(topology, 0, hwloc_cpuset, flags);
+}
+
+static int
+hwloc_netbsd_get_thisproc_cpubind(hwloc_topology_t topology, hwloc_bitmap_t hwloc_cpuset, int flags)
+{
+  return hwloc_netbsd_get_proc_cpubind(topology, 0, hwloc_cpuset, flags);
+}
+
+
+static int
+hwloc_netbsd_set_thread_cpubind(hwloc_topology_t topology __hwloc_attribute_unused, hwloc_thread_t tid, hwloc_const_bitmap_t hwloc_cpuset, int flags __hwloc_attribute_unused)
+{
+  int status;
+  cpuset_t *cpuset = cpuset_create();
+
+  hwloc_netbsd_hwloc2bsd(hwloc_cpuset, cpuset);
+
+  status = pthread_setaffinity_np(tid, cpuset_size(cpuset), cpuset);
+
+  cpuset_destroy(cpuset);
+
+  if (status) {
+    errno = status;
+    return -1;
+  }
+
+  return 0;
+}
+
+static int
+hwloc_netbsd_get_thread_cpubind(hwloc_topology_t topology __hwloc_attribute_unused, hwloc_thread_t tid, hwloc_bitmap_t hwloc_cpuset, int flags __hwloc_attribute_unused)
+{
+  int status;
+  cpuset_t *cpuset = cpuset_create();
+
+  status = pthread_getaffinity_np(tid, cpuset_size(cpuset), cpuset);
+
+  hwloc_netbsd_bsd2hwloc(hwloc_cpuset, cpuset);
+  cpuset_destroy(cpuset);
+
+  if (status) {
+    errno = status;
+    return -1;
+  }
+
+  return 0;
+}
+
+
+static int
+hwloc_netbsd_set_thisthread_cpubind(hwloc_topology_t topology, hwloc_const_bitmap_t hwloc_cpuset, int flags)
+{
+  return hwloc_netbsd_set_thread_cpubind(topology, pthread_self(), hwloc_cpuset, flags);
+}
+
+static int
+hwloc_netbsd_get_thisthread_cpubind(hwloc_topology_t topology, hwloc_bitmap_t hwloc_cpuset, int flags)
+{
+  return hwloc_netbsd_get_thread_cpubind(topology, pthread_self(), hwloc_cpuset, flags);
+}
+
+
+void
+hwloc_look_netbsd(struct hwloc_topology *topology)
+{
+  unsigned nbprocs = hwloc_fallback_nbprocessors(topology);
+
+  hwloc_set_netbsd_hooks(topology);
+  hwloc_look_x86(topology, nbprocs);
+
+  hwloc_setup_pu_level(topology, nbprocs);
+
+  hwloc_obj_add_info(topology->levels[0][0], "Backend", "NetBSD");
+}
+
+void
+hwloc_set_netbsd_hooks(struct hwloc_topology *topology)
+{
+  topology->set_proc_cpubind = hwloc_netbsd_set_proc_cpubind;
+  topology->get_proc_cpubind = hwloc_netbsd_get_proc_cpubind;
+  topology->set_thisproc_cpubind = hwloc_netbsd_set_thisproc_cpubind;
+  topology->get_thisproc_cpubind = hwloc_netbsd_get_thisproc_cpubind;
+
+  topology->set_thread_cpubind = hwloc_netbsd_set_thread_cpubind;
+  topology->get_thread_cpubind = hwloc_netbsd_get_thread_cpubind;
+  topology->set_thisthread_cpubind = hwloc_netbsd_set_thisthread_cpubind;
+  topology->get_thisthread_cpubind = hwloc_netbsd_get_thisthread_cpubind;
+}
