$NetBSD: patch-libexfat__io.c,v 1.1 2022/10/06 00:51:49 perseant Exp $

Add working NetBSD disk sizing.

--- libexfat/io.c	2018-09-14 22:03:24.000000000 -0700
+++ libexfat/io.c	2022-09-27 09:23:55.645533399 -0700
@@ -35,6 +35,10 @@
 #include <sys/disklabel.h>
 #include <sys/dkio.h>
 #include <sys/ioctl.h>
+#elif defined(__NetBSD__)
+#include <sys/param.h>
+#include <util.h>
+#include "nbpartutil.h"
 #elif __linux__
 #include <sys/mount.h>
 #endif
@@ -226,6 +230,28 @@
 					"you can fix this with fdisk(8)");
 	}
 	else
+#elif defined(__NetBSD__)
+	if (!S_ISREG(stbuf.st_mode))
+	{
+		if (stbuf.st_size != 0) {
+			dev->size = stbuf.st_size;
+		} else {
+			char device[MAXPATHLEN];
+			u_int secsize;
+			off_t dksize;
+
+			/* mkexfatfs can only use the block device, but */
+			/* getdisksize() needs the raw device name      */
+			getdiskrawname(device, sizeof(device), spec);
+			getdisksize(device, &secsize, &dksize);
+			dev->size = secsize * dksize;
+		}
+		if (dev->size <= 0) {
+			exfat_error("Unable to determine file system size");
+			return NULL;
+		}
+	}
+	else
 #endif
 	{
 		/* works for Linux, FreeBSD, Solaris */
