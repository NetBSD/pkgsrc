$NetBSD: patch-libntfs-3g_device.c,v 1.1 2014/05/19 12:22:06 adam Exp $

--- libntfs-3g/device.c.orig	2014-02-15 14:07:52.000000000 +0000
+++ libntfs-3g/device.c
@@ -95,6 +95,10 @@
 #	define BLKBSZSET _IOW(0x12,113,size_t) /* Set device block size in bytes. */
 #endif
 
+#if defined(__NetBSD__)
+#include <sys/disklabel.h> /* XXX autoconf this ? */
+#endif
+
 /**
  * ntfs_device_alloc - allocate an ntfs device structure and pre-initialize it
  * @name:	name of the device (must be present)
@@ -596,6 +600,23 @@ s64 ntfs_device_size_get(struct ntfs_dev
 		}
 	}
 #endif
+#ifdef DIOCGPART
+	{
+		struct stat st;
+		if (dev->d_ops->stat(dev, &st) >= 0) {
+			struct disklabel disklabel;
+			int secsize;
+			s64 psize;
+			if (dev->d_ops->ioctl(dev, DIOCGDINFO, &disklabel) >= 0) {
+				secsize = disklabel.d_secsize;
+				psize = disklabel.d_partitions[DISKPART(st.st_rdev)].p_size;
+				ntfs_log_debug("DIOCGPART nr %d byte blocks = %lld (0x%llx)\n",
+						secsize, psize, psize);
+				return psize * secsize / block_size;
+			}
+		}
+	}
+#endif
 	/*
 	 * We couldn't figure it out by using a specialized ioctl,
 	 * so do binary search to find the size of the device.
