$NetBSD: patch-mono_utils_mono-os-semaphore.h,v 1.1 2021/03/03 12:05:41 nia Exp $

XXX netbsd will return EBUSY if we try to destroy a semaphore
that something is waiting on. This apparently occurs in practice.

--- mono/utils/mono-os-semaphore.h.orig	2019-07-18 07:46:08.000000000 +0000
+++ mono/utils/mono-os-semaphore.h
@@ -190,6 +190,8 @@ mono_os_sem_destroy (MonoSemType *sem)
 	int res;
 
 	res = sem_destroy (sem);
+	if ((res != 0) && (errno = EBUSY))
+		res = 0;
 	if (G_UNLIKELY (res != 0))
 		g_error ("%s: sem_destroy failed with \"%s\" (%d)", __func__, g_strerror (errno), errno);
 }
