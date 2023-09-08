$NetBSD: patch-libntfs-3g_device.c,v 1.2 2023/09/08 10:23:07 vins Exp $

Use DIOCGPARTINFO on NetBSD to get the device size in blocks.

--- libntfs-3g/device.c.orig	2022-10-20 15:33:44.000000000 +0000
+++ libntfs-3g/device.c
@@ -95,6 +95,11 @@
 #	define BLKBSZSET _IOW(0x12,113,size_t) /* Set device block size in bytes. */
 #endif
 
+#if defined(__NetBSD__)
+#include <sys/disklabel.h> /* XXX autoconf this ? */
+#include <sys/dkio.h>
+#endif
+
 /**
  * ntfs_device_alloc - allocate an ntfs device structure and pre-initialize it
  * @name:	name of the device (must be present)
@@ -596,6 +601,24 @@ s64 ntfs_device_size_get(struct ntfs_dev
 		}
 	}
 #endif
+#ifdef DIOCGPARTINFO
+	{
+		/* NetBSD */
+		struct stat st;
+		if (dev->d_ops->stat(dev, &st) >= 0) {
+			struct disklabel disklabel;
+			int secsize;
+			s64 psize;
+			if (dev->d_ops->ioctl(dev, DIOCGDINFO, &disklabel) >= 0) {
+				secsize = disklabel.d_secsize;
+				psize = disklabel.d_partitions[DISKPART(st.st_rdev)].p_size;
+				ntfs_log_debug("DIOCGPARTINFO nr %d byte blocks = %lld (0x%llx)\n",
+						secsize, psize, psize);
+				return psize * secsize / block_size;
+			}
+		}
+	}
+#endif
 	/*
 	 * We couldn't figure it out by using a specialized ioctl,
 	 * so do binary search to find the size of the device.
