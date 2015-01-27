$NetBSD: patch-coda-src_venus_worker.cc,v 1.2 2015/01/27 19:40:24 gdt Exp $

Added experimental code to support mounting on NetBSD >= 4.99.24. The
magic value of 256 is taken from coda_vfsops in coda_vfsops.c.
Sent upstream on 2011-03-11 and again on 2015-01-27.

gcc 4.7 on SunOS insists on de-'const'ifying venusRoot.

--- coda-src/venus/worker.cc.orig	2008-10-06 16:52:22.000000000 +0000
+++ coda-src/venus/worker.cc
@@ -403,11 +403,19 @@ void VFSMount()
 	    error = nmount(md, 6, 0);
 	}
 #endif
-			
+
+#if defined(__NetBSD__) && __NetBSD_Version__ >= 499002400   /* 4.99.24 */
+	if (error < 0)
+	    error = mount("coda", venusRoot, 0, (void *)kernDevice, 256);
+	if (error < 0)
+	    error = mount("cfs", venusRoot, 0, (void *)kernDevice, 256);
+#else
 	if (error < 0)
 	    error = mount("coda", venusRoot, 0, kernDevice);
 	if (error < 0)
 	    error = mount("cfs", venusRoot, 0, kernDevice);
+#endif
+
 #if defined(__FreeBSD__) && !defined(__FreeBSD_version)
 #define MOUNT_CFS 19
 	if (error < 0)
@@ -492,7 +500,8 @@ child_done:
 	  mnttab = fopen(MNTTAB, "a+");
 	  if (mnttab != NULL) {
 	    mt.mnt_special = "CODA";
-	    mt.mnt_mountp = venusRoot;
+            /* XXX */
+	    mt.mnt_mountp = (char *)venusRoot;
 	    mt.mnt_fstype = "CODA";
 	    mt.mnt_mntopts = "rw";
 	    mt.mnt_time = tm;
