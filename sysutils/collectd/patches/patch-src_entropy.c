$NetBSD: patch-src_entropy.c,v 1.2 2015/08/14 12:59:04 he Exp $

Provide a NetBSD implementation for graphing available entropy.

--- src/entropy.c.orig	2015-03-10 14:14:45.000000000 +0000
+++ src/entropy.c
@@ -29,27 +29,46 @@
 #include "plugin.h"
 
 #if !KERNEL_LINUX
-# error "No applicable input method."
+# if defined(__NetBSD__)
+/* Provide a NetBSD implementation, partial from rndctl.c */
+
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <sys/param.h>
+#include <sys/rnd.h>
+#if HAVE_SYS_RNDIO_H
+# include <sys/rndio.h>
 #endif
 
-#define ENTROPY_FILE "/proc/sys/kernel/random/entropy_avail"
+static void entropy_submit (double);
+static int entropy_read (void);
 
-static void entropy_submit (double entropy)
+static int
+entropy_read (void)
 {
-	value_t values[1];
-	value_list_t vl = VALUE_LIST_INIT;
+	rndpoolstat_t rs;
+	int fd;
 
-	values[0].gauge = entropy;
+	fd = open("/dev/urandom", O_RDONLY, 0644);
+	if (fd < 0)
+		return -1;
 
-	vl.values = values;
-	vl.values_len = 1;
-	sstrncpy (vl.host, hostname_g, sizeof (vl.host));
-	sstrncpy (vl.plugin, "entropy", sizeof (vl.plugin));
-	sstrncpy (vl.type, "entropy", sizeof (vl.type));
+	if (ioctl(fd, RNDGETPOOLSTAT, &rs) < 0)
+		return -1;
 
-	plugin_dispatch_values (&vl);
+	entropy_submit (rs.curentropy);
+
+	close(fd);
+	return 0;
 }
 
+# else /* not NetBSD */
+#  error "No applicable input method."
+# endif
+#else /* Linux */
+
+#define ENTROPY_FILE "/proc/sys/kernel/random/entropy_avail"
+
 static int entropy_read (void)
 {
 	double entropy;
@@ -74,6 +93,23 @@ static int entropy_read (void)
 
 	return (0);
 }
+#endif /* not Linux */
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
