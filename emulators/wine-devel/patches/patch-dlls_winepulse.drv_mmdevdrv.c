$NetBSD: patch-dlls_winepulse.drv_mmdevdrv.c,v 1.1 2016/09/15 09:25:53 maya Exp $

Check for pthread_mutexattr_setprotocol.

--- dlls/winepulse.drv/mmdevdrv.c.orig	2016-06-10 14:04:01.000000000 +0000
+++ dlls/winepulse.drv/mmdevdrv.c
@@ -98,7 +98,9 @@ BOOL WINAPI DllMain(HINSTANCE dll, DWORD
         DisableThreadLibraryCalls(dll);
 
         pthread_mutexattr_init(&attr);
+#ifdef HAVE_PTHREAD_MUTEXATTR_SETPROTOCOL
         pthread_mutexattr_setprotocol(&attr, PTHREAD_PRIO_INHERIT);
+#endif
 
         if (pthread_mutex_init(&pulse_lock, &attr) != 0)
             pthread_mutex_init(&pulse_lock, NULL);
