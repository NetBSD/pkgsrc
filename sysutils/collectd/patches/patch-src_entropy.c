$NetBSD: patch-src_entropy.c,v 1.6 2015/12/12 22:23:32 he Exp $

Provide a NetBSD implementation for graphing available entropy.
This version tries to keep /dev/urandom open (for repeated use),
instead of constantly re-opening/closing it, since the latter will
needlessly reduce the kernel's entropy estimate.

--- src/entropy.c.orig	2015-03-10 14:14:45.000000000 +0000
+++ src/entropy.c
@@ -28,27 +28,16 @@
 #include "common.h"
 #include "plugin.h"
 
-#if !KERNEL_LINUX
-# error "No applicable input method."
-#endif
-
-#define ENTROPY_FILE "/proc/sys/kernel/random/entropy_avail"
-
-static void entropy_submit (double entropy)
-{
-	value_t values[1];
-	value_list_t vl = VALUE_LIST_INIT;
+static void entropy_submit (double);
+static int entropy_read (void);
 
-	values[0].gauge = entropy;
+#if !KERNEL_LINUX && !KERNEL_NETBSD
+#  error "No applicable input method."
+#endif
 
-	vl.values = values;
-	vl.values_len = 1;
-	sstrncpy (vl.host, hostname_g, sizeof (vl.host));
-	sstrncpy (vl.plugin, "entropy", sizeof (vl.plugin));
-	sstrncpy (vl.type, "entropy", sizeof (vl.type));
+#if KERNEL_LINUX
 
-	plugin_dispatch_values (&vl);
-}
+#define ENTROPY_FILE "/proc/sys/kernel/random/entropy_avail"
 
 static int entropy_read (void)
 {
@@ -74,6 +63,68 @@ static int entropy_read (void)
 
 	return (0);
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
+	rndpoolstat_t rs;
+	static int fd;
+
+	if (fd == 0) {
+		fd = open(_PATH_URANDOM, O_RDONLY, 0644);
+		if (fd < 0) {
+			fd = 0;
+			return -1;
+		}
+	}
+
+	if (ioctl(fd, RNDGETPOOLSTAT, &rs) < 0) {
+		(void) close(fd);
+		fd = 0; /* signal a reopening on next attempt */
+		return -1;
+	}
+
+	entropy_submit (rs.curentropy);
+
+	return 0;
+}
+
+#endif /* KERNEL_NETBSD */
+
+static void entropy_submit (double entropy)
+{
+	value_t values[1];
+	value_list_t vl = VALUE_LIST_INIT;
+
+	values[0].gauge = entropy;
+
+	vl.values = values;
+	vl.values_len = 1;
+	sstrncpy (vl.host, hostname_g, sizeof (vl.host));
+	sstrncpy (vl.plugin, "entropy", sizeof (vl.plugin));
+	sstrncpy (vl.type, "entropy", sizeof (vl.type));
+
+	plugin_dispatch_values (&vl);
+}
 
 void module_register (void)
 {
