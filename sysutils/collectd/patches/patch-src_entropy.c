$NetBSD: patch-src_entropy.c,v 1.10 2017/11/21 15:18:23 fhajny Exp $

Provide a NetBSD implementation for graphing available entropy.
This version tries to keep /dev/urandom open (for repeated use),
instead of constantly re-opening/closing it, since the latter will
needlessly reduce the kernel's entropy estimate.

--- src/entropy.c.orig	2017-11-18 09:03:27.354750373 +0000
+++ src/entropy.c
@@ -29,23 +29,16 @@
 #include "common.h"
 #include "plugin.h"
 
-#if !KERNEL_LINUX
+static void entropy_submit (value_t);
+static int entropy_read (void);
+
+#if !KERNEL_LINUX && !KERNEL_NETBSD
 #error "No applicable input method."
 #endif
 
+#if KERNEL_LINUX
 #define ENTROPY_FILE "/proc/sys/kernel/random/entropy_avail"
 
-static void entropy_submit(value_t value) {
-  value_list_t vl = VALUE_LIST_INIT;
-
-  vl.values = &value;
-  vl.values_len = 1;
-  sstrncpy(vl.plugin, "entropy", sizeof(vl.plugin));
-  sstrncpy(vl.type, "entropy", sizeof(vl.type));
-
-  plugin_dispatch_values(&vl);
-}
-
 static int entropy_read(void) {
   value_t v;
   if (parse_value_file(ENTROPY_FILE, &v, DS_TYPE_GAUGE) != 0) {
@@ -56,6 +49,70 @@ static int entropy_read(void) {
   entropy_submit(v);
   return 0;
 }
+#endif /* KERNEL_LINUX */
+
+#if KERNEL_NETBSD
+/* Provide a NetBSD implementation, partial from rndctl.c */
+
+/*
+ * Improved to keep the /dev/urandom open, since there's a consumption
+ * of entropy from /dev/random for every open of /dev/urandom, and this
+ * will end up opening /dev/urandom lots of times.
+ */
+
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <sys/param.h>
+#include <sys/rnd.h>
+#if HAVE_SYS_RNDIO_H
+# include <sys/rndio.h>
+#endif
+#include <paths.h>
+
+static int
+entropy_read (void)
+{
+  value_t v;
+  rndpoolstat_t rs;
+  static int fd;
+  char buf[30];
+
+  if (fd == 0) {
+    fd = open(_PATH_URANDOM, O_RDONLY, 0644);
+    if (fd < 0) {
+      fd = 0;
+      return -1;
+    }
+  }
+
+  if (ioctl(fd, RNDGETPOOLSTAT, &rs) < 0) {
+    (void) close(fd);
+    fd = 0; /* signal a reopening on next attempt */
+    return -1;
+  }
+  snprintf(buf, sizeof(buf), "%ju", (uintmax_t)rs.curentropy);
+  if (parse_value(buf, &v, DS_TYPE_GAUGE) != 0) {
+    ERROR("entropy plugin: Parsing \"%s\" failed.", buf);
+    return (-1);
+  }
+
+  entropy_submit (v);
+
+  return 0;
+}
+
+#endif /* KERNEL_NETBSD */
+
+static void entropy_submit(value_t value) {
+  value_list_t vl = VALUE_LIST_INIT;
+
+  vl.values = &value;
+  vl.values_len = 1;
+  sstrncpy(vl.plugin, "entropy", sizeof(vl.plugin));
+  sstrncpy(vl.type, "entropy", sizeof(vl.type));
+
+  plugin_dispatch_values(&vl);
+}
 
 void module_register(void) {
   plugin_register_read("entropy", entropy_read);
