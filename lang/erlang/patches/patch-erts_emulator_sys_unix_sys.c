$NetBSD: patch-erts_emulator_sys_unix_sys.c,v 1.1 2016/10/04 07:21:30 he Exp $

Don't invade the implementation namespace.
There's no guarantee that __errno is free for own use
(on NetBSD it isn't!)

--- erts/emulator/sys/unix/sys.c.orig	2016-09-20 19:11:23.000000000 +0000
+++ erts/emulator/sys/unix/sys.c
@@ -715,13 +715,13 @@ static RETSIGTYPE suspend_signal(void)
 static RETSIGTYPE suspend_signal(int signum)
 #endif
 {
-    int res, buf[1], __errno = errno;
+    int res, buf[1], save_errno = errno;
     do {
         res = read(sig_suspend_fds[0], buf, sizeof(int));
     } while (res < 0 && errno == EINTR);
 
     /* restore previous errno in case read changed it */
-    errno = __errno;
+    errno = save_errno;
 }
 #endif /* #ifdef ERTS_SYS_SUSPEND_SIGNAL */
 
