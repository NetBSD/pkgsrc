$NetBSD: patch-scsitape.c,v 1.2 2013/10/15 14:14:53 ryoon Exp $

--- scsitape.c.orig	2013-06-14 21:32:42.000000000 +0000
+++ scsitape.c
@@ -1261,7 +1261,11 @@ int readblkid_scsitape ( DEVBLK* dev, BY
     // value, also known as the >>LOGICAL<< value and *NOT*
     // the absolute/physical device-relative value)
 
+#if defined(BSD) && BSD >= 199306
+    struct  mtget  mtpos;
+#else
     struct  mtpos  mtpos;
+#endif
     BYTE    blockid[4];
 
     if (ioctl_tape( dev->fd, MTIOCPOS, (char*) &mtpos ) < 0 )
@@ -1326,6 +1330,19 @@ int locateblk_scsitape ( DEVBLK* dev, U3
     mtop.mt_count = CSWAP32( mtop.mt_count );   // (host <- guest)
     mtop.mt_op    = MTSEEK;
 
+#if defined(BSD) && BSD >= 199306
+    /* Find out where we are so we can do a relative seek */
+    {
+	struct mtget here;
+
+	rc = ioctl_tape( dev->fd, MTIOCGET, (char*)&here );
+	if (rc >= 0) {
+	    mtop.mt_count -= here.mt_blkno;
+	    mtop.mt_op = MTFSR;
+	}
+    }
+#endif /* BSD */
+
     // Ask the actual hardware to do an actual physical locate...
 
     if ((rc = ioctl_tape( dev->fd, MTIOCTOP, (char*)&mtop )) < 0)
