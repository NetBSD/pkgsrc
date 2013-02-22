$NetBSD: patch-ROX-Filer_src_mount.c,v 1.1 2013/02/22 21:38:06 jperkin Exp $

Re-order includes so the correct ones are used on SunOS.

--- ROX-Filer/src/mount.c.orig	2009-07-18 14:23:18.000000000 +0000
+++ ROX-Filer/src/mount.c
@@ -29,6 +29,10 @@
 #ifdef HAVE_MNTENT_H
   /* Linux, etc */
 # include <mntent.h>
+#elif HAVE_SYS_MNTENT_H
+  /* SunOS */
+# include <sys/mntent.h>
+# include <sys/mnttab.h>
 #elif HAVE_SYS_UCRED_H
   /* NetBSD, OSF1, etc */
 # include <fstab.h>
@@ -37,10 +41,6 @@
 # include <sys/ucred.h>
 # include <sys/mount.h>
 # include <stdlib.h>
-#elif HAVE_SYS_MNTENT_H
-  /* SunOS */
-# include <sys/mntent.h>
-# include <sys/mnttab.h>
 #endif
 #include <sys/time.h>
 #ifdef HAVE_SYS_VFS_H
