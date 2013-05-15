$NetBSD: patch-qemu-xen-traditional_block-raw-posix.c,v 1.1 2013/05/15 06:58:50 jnemeth Exp $

- if given a block device, use the character device instead.

--- qemu-xen-traditional/block-raw-posix.c.orig	2012-12-11 13:11:04.000000000 +0000
+++ qemu-xen-traditional/block-raw-posix.c
@@ -65,6 +65,7 @@
 #include <sys/disklabel.h>
 #include <sys/dkio.h>
 #include <sys/disk.h>
+#include <sys/param.h>
 #endif
 
 #ifdef __OpenBSD__
@@ -72,6 +73,13 @@
 #include <sys/disklabel.h>
 #include <sys/dkio.h>
 #endif
+#if defined(__NetBSD__)
+#include <sys/ioctl.h>
+#include <sys/disklabel.h>
+#include <sys/dkio.h>
+#define SLIST_ENTRY(x) int /*XXXX !*/
+#include <sys/disk.h>
+#endif
 
 //#define DEBUG_FLOPPY
 
@@ -1008,6 +1016,33 @@ static int hdev_open(BlockDriverState *b
 {
     BDRVRawState *s = bs->opaque;
     int fd, open_flags, ret;
+#ifdef __NetBSD__
+    struct stat sb;
+    static char namebuf[MAXPATHLEN];
+    const char *dp;
+
+    if (lstat(filename, &sb) < 0) {
+	fprintf(stderr, "%s: stat failed: %s\n", filename, strerror(errno));
+	return -errno;
+    }
+    if (S_ISLNK(sb.st_mode)) {
+	fprintf(stderr, "%s: symolink links not supported by qemu-dm\n",
+	    filename);
+	return -EINVAL;
+    }
+    if (S_ISBLK(sb.st_mode)) {
+	dp = strrchr(filename, '/');
+	if (dp == NULL) {
+		snprintf(namebuf, MAXPATHLEN, "r%s", filename);
+	} else {
+		snprintf(namebuf, MAXPATHLEN, "%.*s/r%s",
+		    (int)(dp - filename), filename, dp + 1);
+	}
+	fprintf(stderr, "%s is a block device", filename);
+	filename = namebuf;
+	fprintf(stderr, ", using %s\n", filename);
+    }
+#endif
 
     posix_aio_init();
 
