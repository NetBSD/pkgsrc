$NetBSD: patch-libdaemon_dexec.c,v 1.1 2012/12/27 17:01:23 bsiegert Exp $

MirBSD does not have ECANCELED. EINTR is not really the right return value.
IMHO, it should return with exit status set to 127 instead.

--- libdaemon/dexec.c.orig	Thu Dec 13 00:17:52 2012
+++ libdaemon/dexec.c
@@ -203,7 +203,11 @@ int daemon_execv(const char *dir, int *r
             return -1;
         } else {
             if (!WIFEXITED(r)) {
+#ifdef ECANCELED
                 errno = ECANCELED;
+#else
+                errno = EINTR; /* The child was terminated by a signal. */
+#endif
                 return -1;
             }
 
