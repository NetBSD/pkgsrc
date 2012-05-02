$NetBSD: patch-src-afs-NBSD-osi_kmod.c,v 1.1 2012/05/02 23:19:25 christos Exp $

--- src/afs/NBSD/osi_kmod.c.orig	2012-04-22 23:40:23.000000000 -0400
+++ src/afs/NBSD/osi_kmod.c	2012-04-30 16:47:59.000000000 -0400
@@ -64,6 +64,62 @@
 static sy_call_t *old_setgroups;
 static sy_call_t *old_ioctl;
 
+static int
+afs_syscall_establish(struct sysent *se)
+{
+	if (old_ioctl != NULL)
+		return EBUSY;
+
+	old_sysent = se[AFS_SYSCALL];
+	old_setgroups = se[SYS_setgroups].sy_call;
+	old_ioctl = se[SYS_ioctl].sy_call;
+
+	if (
+#if defined(AFS_NBSD60_ENV)
+# define LOCK() kernconfig_lock()
+# define UNLOCK() kernconfig_unlock()
+# ifndef RUMP
+	    old_sysent.sy_call != sys_nosys
+# else
+	    false
+# endif
+#else
+# define LOCK()
+# define UNLOCK()
+	    old_sysent.sy_call != sys_lkmnosys
+#endif
+	) {
+		old_ioctl = NULL;
+		return EBUSY;
+	}
+
+	LOCK();
+	se[AFS_SYSCALL] = openafs_sysent;
+	se[SYS_setgroups].sy_call = Afs_xsetgroups;
+	se[SYS_ioctl].sy_call = afs_xioctl;
+	UNLOCK();
+
+	return 0;
+}
+
+static int
+afs_syscall_disestablish(struct sysent *se)
+{
+	if (old_ioctl == NULL)
+		return EINVAL;
+
+	/* XXX: Need to do more work here like the kernel function does */
+
+	LOCK();
+	se[SYS_ioctl].sy_call = old_ioctl;
+	se[SYS_setgroups].sy_call = old_setgroups;
+	se[AFS_SYSCALL] = old_sysent;
+	UNLOCK();
+
+	old_ioctl = NULL;
+	return 0;
+}
+
 MODULE(MODULE_CLASS_VFS, openafs, NULL);
 
 static int
@@ -80,53 +136,21 @@
 
 	switch (cmd) {
 	case MODULE_CMD_INIT:
+		if ((error = afs_syscall_establish(se)) != 0)
+			return error;
 		error = vfs_attach(&afs_vfsops);
-		if (error != 0)
-			break;
-		old_sysent = se[AFS_SYSCALL];
-		old_setgroups = se[SYS_setgroups].sy_call;
-		old_ioctl = se[SYS_ioctl].sy_call;
-#if defined(AFS_NBSD60_ENV)
-# ifndef RUMP
-		if (old_sysent.sy_call == sys_nosys) {
-# else
-		if (true) {
-# endif
-#else
-		if (old_sysent.sy_call == sys_lkmnosys) {
-#endif
-#if defined(AFS_NBSD60_ENV)
-			kernconfig_lock();
-#endif
-			se[AFS_SYSCALL] = openafs_sysent;
-			se[SYS_setgroups].sy_call = Afs_xsetgroups;
-			se[SYS_ioctl].sy_call = afs_xioctl;
-#if defined(AFS_NBSD60_ENV)
-			kernconfig_unlock();
-#endif
-		} else {
-			error = EBUSY;
+		if (error != 0) {
+			afs_syscall_disestablish(se);
+			return error;
 		}
-		if (error != 0)
-			break;
-		break;
+		return 0;
 	case MODULE_CMD_FINI:
-#if defined(AFS_NBSD60_ENV)
-		kernconfig_lock();
-#endif
-		se[SYS_ioctl].sy_call = old_ioctl;
-		se[SYS_setgroups].sy_call = old_setgroups;
-		se[AFS_SYSCALL] = old_sysent;
-#if defined(AFS_NBSD60_ENV)
-		kernconfig_unlock();
-#endif
-		error = vfs_detach(&afs_vfsops);
-		if (error != 0)
-			break;
-		break;
+		if ((error = vfs_detach(&afs_vfsops)) != 0)
+			return error;
+		return afs_syscall_disestablish(se);
+
 	default:
-		error = ENOTTY;
-		break;
+		return ENOTTY;
 	}
 
 	return error;
