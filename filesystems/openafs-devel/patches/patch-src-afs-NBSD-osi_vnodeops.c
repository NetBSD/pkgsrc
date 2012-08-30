$NetBSD: patch-src-afs-NBSD-osi_vnodeops.c,v 1.1 2012/08/30 17:37:55 jakllsch Exp $

--- src/afs/NBSD/osi_vnodeops.c.orig	2012-04-22 23:40:23.000000000 -0400
+++ src/afs/NBSD/osi_vnodeops.c	2012-04-30 16:47:20.000000000 -0400
@@ -274,7 +274,14 @@
     struct nbvdata *vd;
 
     KASSERT(AFSTOV(tvc) == NULL);
-    while (getnewvnode(VT_AFS, afs_globalVFS, afs_vnodeop_p, &AFSTOV(tvc))) {
+    while (getnewvnode(VT_AFS, afs_globalVFS, afs_vnodeop_p,
+#ifdef AFS_NBSD70_ENV
+	NULL,
+#define AMP 
+#else
+#define AMP &
+#endif
+	&AFSTOV(tvc))) {
 	/* no vnodes available, force an alloc (limits be damned)! */
 	printf("afs: upping desiredvnodes\n");
 	desiredvnodes++;
@@ -282,15 +289,15 @@
 
     vd = kmem_zalloc(sizeof(*vd), KM_SLEEP);
 #ifdef AFS_NBSD50_ENV
-    mutex_enter(&AFSTOV(tvc)->v_interlock);
+    mutex_enter(AMP AFSTOV(tvc)->v_interlock);
 #else
-    simple_lock(&AFSTOV(tvc)->v_interlock);
+    simple_lock(AMP AFSTOV(tvc)->v_interlock);
 #endif
     vd->afsvc = tvc;
     AFSTOV(tvc)->v_data = vd;
     genfs_node_init(AFSTOV(tvc), &afs_genfsops);
 #ifdef AFS_NBSD50_ENV
-    mutex_exit(&AFSTOV(tvc)->v_interlock);
+    mutex_exit(AMP AFSTOV(tvc)->v_interlock);
 #else
     simple_unlock(&AFSTOV(tvc)->v_interlock);
 #endif
