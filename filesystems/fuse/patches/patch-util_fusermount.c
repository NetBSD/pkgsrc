$NetBSD: patch-util_fusermount.c,v 1.1 2012/03/10 20:59:52 markd Exp $

Fix error 'CLONE_NEWNS' undeclared on recent linux.  From git.

--- util/fusermount.c.orig	2010-04-26 12:15:36.000000000 +0000
+++ util/fusermount.c
@@ -7,6 +7,7 @@
 */
 /* This program does the mounting and unmounting of FUSE filesystems */
 
+#define _GNU_SOURCE /* for clone */
 #include <config.h>
 
 #include "mount_util.h"
