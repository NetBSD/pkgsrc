$NetBSD: patch-src_getsize.c,v 1.1 2013/12/11 19:07:47 prlw1 Exp $

- Make unimplemented getsize() function match prototype in getsize.h.
- Use ioctl names (feature tests) rather than OS names.
  XXX for SIOC_CAPACITY consider using SIOC_STORAGE_CAPACITY.
- Implement getsize() based on DIOCGDISKINFO ioctl.

--- src/getsize.c.orig	2013-12-11 17:24:25.000000000 +0000
+++ src/getsize.c
@@ -36,16 +36,35 @@
 #include <stdlib.h>
 #include <libgen.h>
 #include <string.h>
+#if HAVE_STDINT_H
+#include <stdint.h>
+#endif
+#if HAVE_SYS_IOCTL_H
+#include <sys/ioctl.h>
+#endif
+#if HAVE_LINUX_FS_H
+#include <linux/fs.h>
+#endif
+#if HAVE_SYS_DEVINFO_H
+#include <sys/devinfo.h>
+#endif
+#if HAVE_SYS_DISK_H
+#include <sys/disk.h>
+#endif
+#if HAVE_SYS_DKIO_H
+#include <sys/dkio.h>
+#endif
+#if HAVE_SYS_SCSI_H
+#include <sys/scsi.h>
+#endif
 
 #include "getsize.h"
 
 extern char *prog;
 
-#if defined(linux)
+#if defined (BLKGETSIZE) && defined(BLKGETSIZE64)
 /* scrub-1.7 tested linux 2.6.11-1.1369_FC4 */
 /* scrub-1.8 tested Fedora Core 5 */
-#include <sys/ioctl.h>
-#include <linux/fs.h>
 #include <sys/utsname.h>
 typedef unsigned long long u64; /* for BLKGETSIZE64 (slackware) */
 
@@ -86,11 +105,8 @@ error:
     return -1;
 }
 
-#elif defined(__FreeBSD__)
+#elif defined(DIOCGMEDIASIZE)
 /* scrub-1.7 tested freebsd 5.3-RELEASE-p5 */
-#include <sys/ioctl.h>
-#include <sys/disk.h>
-
 int
 getsize(char *path, off_t *sizep)
 {
@@ -111,10 +127,8 @@ error:
     return -1;
 }
 
-#elif defined(sun)
+#elif defined(DKIOCGMEDIAINFO)
 /* scrub-1.7 tested solaris 5.9 */
-#include <sys/ioctl.h>
-#include <sys/dkio.h>
 #include <sys/vtoc.h>
 
 int
@@ -137,11 +151,8 @@ error:
     return -1;
 }
 
-#elif defined(__APPLE__)
+#elif defined(DKIOCGETBLOCKSIZE) && defined(DKIOCGETBLOCKCOUNT)
 /* scrub-1.7 tested OS X 7.9.0 */
-#include <stdint.h>
-#include <sys/ioctl.h>
-#include <sys/disk.h>
 
 int
 getsize(char *path, off_t *sizep)
@@ -165,11 +176,10 @@ error:
         (void)close(fd);
     return -1;
 }
-#elif defined(_AIX)
+
+#elif defined(IOCINFO)
 /* scrub-1.7 tested AIX 5.1 and 5.3 */
 /* scrub-1.8 tested AIX 5.2 */
-#include <sys/ioctl.h>
-#include <sys/devinfo.h>
 
 int
 getsize(char *path, off_t *sizep)
@@ -202,10 +212,10 @@ error:
         (void)close(fd);
     return -1;
 }
-#elif defined (__hpux)
+
+#elif defined (SIOC_CAPACITY)
 
 #include <stropts.h>
-#include <sys/scsi.h>
 
 int
 getsize(char *path, off_t *sizep)
@@ -227,11 +237,43 @@ error:
     return -1;
 }
 
+#elif defined(DIOCGDISKINFO)
+
+int
+getsize(char *path, off_t *sizep)
+{
+    int fd;
+    prop_dictionary_t disk_dict, geom_dict;
+    uint64_t secperunit;
+    uint32_t secsize;
+
+    fd = open(path, O_RDONLY);
+    if (fd == -1)
+        return -1;
+
+    if (prop_dictionary_recv_ioctl(fd, DIOCGDISKINFO, &disk_dict) != 0)
+        return -1;
+    if (close(fd) == -1)
+        return -1;
+
+    geom_dict = prop_dictionary_get(disk_dict, "geometry");
+    if (geom_dict == NULL)
+        return -1;
+
+    if (!prop_dictionary_get_uint64(geom_dict, "sectors-per-unit", &secperunit))
+        return -1;
+    if (!prop_dictionary_get_uint32(geom_dict, "sector-size",      &secsize))
+        return -1;
+    *sizep = secperunit * secsize;
+
+    return 0;
+}
+
 #else
 /* Unimplemented!  Scrub will tell user to use -s.
  */
-off_t 
-getsize(char *path)
+int
+getsize(char *path, off_t *sizep)
 {
     errno = ENOSYS;
     return -1;
