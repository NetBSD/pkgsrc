$NetBSD: patch-src_osdep_unix_flocklnx.c,v 1.1 2026/04/28 19:35:39 vins Exp $

Prevent unsafe usage of syslog.

--- src/osdep/unix/flocklnx.c.orig	2026-04-28 18:47:34.739732606 +0000
+++ src/osdep/unix/flocklnx.c
@@ -57,7 +57,7 @@ int safe_flock (int fd,int op)
     case ENOLCK:		/* lock table is full */
       sprintf (tmp,"File locking failure: %s",strerror (errno));
       mm_log (tmp,WARN);	/* give the user a warning of what happened */
-      if (!logged++) syslog (LOG_ERR,tmp);
+      if (!logged++) syslog (LOG_ERR,"%s", tmp);
 				/* return failure if non-blocking lock */
       if (op & LOCK_NB) return -1;
       sleep (5);		/* slow down in case it loops */
