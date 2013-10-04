$NetBSD: patch-xlators_mount_fuse_src_fuse-helpers.c,v 1.3 2013/10/04 08:07:23 manu Exp $

--- xlators/mount/fuse/src/fuse-helpers.c.orig	2013-09-17 13:41:20.000000000 +0000
+++ xlators/mount/fuse/src/fuse-helpers.c
@@ -7,6 +7,10 @@
    later), or the GNU General Public License, version 2 (GPLv2), in all
    cases as published by the Free Software Foundation.
 */
+#ifdef __NetBSD__
+#define _KMEMUSER
+#endif
+
 #include "fuse-bridge.h"
 #if defined(GF_SOLARIS_HOST_OS)
 #include <sys/procfs.h>
