$NetBSD: patch-src-afs-NBSD-osi_vm.c,v 1.1 2012/08/30 17:37:55 jakllsch Exp $

--- src/afs/NBSD/osi_vm.c.orig	2012-04-22 23:40:23.000000000 -0400
+++ src/afs/NBSD/osi_vm.c	2012-04-30 16:47:34.000000000 -0400
@@ -84,7 +84,13 @@
     ReleaseWriteLock(&avc->lock);
     AFS_GUNLOCK();
     vp = AFSTOV(avc);
-    mutex_enter(&vp->v_interlock);
+#ifdef AFS_NBSD70_ENV
+#define AMP
+#else
+#define AMP &
+#endif
+
+    mutex_enter(AMP vp->v_interlock);
     VOP_PUTPAGES(vp, 0, 0, PGO_ALLPAGES|PGO_CLEANIT|PGO_SYNCIO);
     AFS_GLOCK();
     ObtainWriteLock(&avc->lock, 94);
