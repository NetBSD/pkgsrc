$NetBSD: patch-scsitape.c,v 1.1 2011/05/01 23:28:59 ryoon Exp $

--- scsitape.c.orig	2010-01-08 22:56:27.000000000 +0000
+++ scsitape.c
@@ -1334,6 +1334,19 @@ int locateblk_scsitape ( DEVBLK* dev, U3
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
