$NetBSD: patch-src_entropy.c,v 1.4 2015/09/01 09:31:46 he Exp $

Provide a NetBSD implementation for graphing available entropy.

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
+static void entropy_submit (double);
+static int entropy_read (void);
 
-static void entropy_submit (double entropy)
-{
-	value_t values[1];
-	value_list_t vl = VALUE_LIST_INIT;
+#if !KERNEL_LINUX && !KERNEL_NETBSD
+#  error "No applicable input method."
+#endif
 
-	values[0].gauge = entropy;
+#if KERNEL_LINUX
 
-	vl.values = values;
-	vl.values_len = 1;
-	sstrncpy (vl.host, hostname_g, sizeof (vl.host));
-	sstrncpy (vl.plugin, "entropy", sizeof (vl.plugin));
-	sstrncpy (vl.type, "entropy", sizeof (vl.type));
-
-	plugin_dispatch_values (&vl);
-}
+#define ENTROPY_FILE "/proc/sys/kernel/random/entropy_avail"
 
 static int entropy_read (void)
 {
@@ -74,6 +63,56 @@ static int entropy_read (void)
 
 	return (0);
 }
+#endif /* KERNEL_LINUX */
+
+#if KERNEL_NETBSD
+/* Provide a NetBSD implementation, partial from rndctl.c */
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
+	int fd;
+
+	fd = open(_PATH_URANDOM, O_RDONLY, 0644);
+	if (fd < 0)
+		return -1;
+
+	if (ioctl(fd, RNDGETPOOLSTAT, &rs) < 0)
+		return -1;
+
+	entropy_submit (rs.curentropy);
+
+	close(fd);
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
