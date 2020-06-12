$NetBSD: patch-posixos.c,v 1.3 2020/06/12 23:50:16 sevan Exp $

http://git.savannah.gnu.org/cgit/make.git/commit/?id=b552b05251980f693c729e251f93f5225b400714

[SV 51159] Use a non-blocking read with pselect to avoid hangs.
* posixos.c (set_blocking): Set blocking on a file descriptor.
* (jobserver_setup): Set non-blocking on the jobserver read side.
* (jobserver_parse_auth): Ditto.
* (jobserver_acquire_all): Set blocking to avoid a busy-wait loop.
* (jobserver_acquire): If the non-blocking read() returns without
  taking a token then try again.

--- posixos.c.orig	2016-05-21 20:21:52.000000000 +0000
+++ posixos.c
@@ -59,6 +59,24 @@ make_job_rfd (void)
 #endif
 }
 
+static void
+set_blocking (int fd, int blocking)
+{
+  // If we're not using pselect() don't change the blocking
+#ifdef HAVE_PSELECT
+  int flags;
+  EINTRLOOP (flags, fcntl (fd, F_GETFL));
+  if (flags >= 0)
+    {
+      int r;
+      flags = blocking ? (flags & ~O_NONBLOCK) : (flags | O_NONBLOCK);
+      EINTRLOOP (r, fcntl (fd, F_SETFL, flags));
+      if (r < 0)
+        pfatal_with_name ("fcntl(O_NONBLOCK)");
+    }
+#endif
+}
+
 unsigned int
 jobserver_setup (int slots)
 {
@@ -78,6 +96,9 @@ jobserver_setup (int slots)
         pfatal_with_name (_("init jobserver pipe"));
     }
 
+  /* When using pselect() we want the read to be non-blocking.  */
+  set_blocking (job_fds[0], 0);
+
   return 1;
 }
 
@@ -113,6 +134,9 @@ jobserver_parse_auth (const char *auth)
       return 0;
     }
 
+  /* When using pselect() we want the read to be non-blocking.  */
+  set_blocking (job_fds[0], 0);
+
   return 1;
 }
 
@@ -161,7 +185,10 @@ jobserver_acquire_all (void)
 {
   unsigned int tokens = 0;
 
-  /* Close the write side, so the read() won't hang.  */
+  /* Use blocking reads to wait for all outstanding jobs.  */
+  set_blocking (job_fds[0], 1);
+
+  /* Close the write side, so the read() won't hang forever.  */
   close (job_fds[1]);
   job_fds[1] = -1;
 
@@ -239,18 +266,12 @@ jobserver_pre_acquire (void)
 unsigned int
 jobserver_acquire (int timeout)
 {
-  sigset_t empty;
-  fd_set readfds;
   struct timespec spec;
   struct timespec *specp = NULL;
-  int r;
-  char intake;
+  sigset_t empty;
 
   sigemptyset (&empty);
 
-  FD_ZERO (&readfds);
-  FD_SET (job_fds[0], &readfds);
-
   if (timeout)
     {
       /* Alarm after one second (is this too granular?)  */
@@ -259,28 +280,52 @@ jobserver_acquire (int timeout)
       specp = &spec;
     }
 
-  r = pselect (job_fds[0]+1, &readfds, NULL, NULL, specp, &empty);
-
-  if (r == -1)
+  while (1)
     {
-      /* Better be SIGCHLD.  */
-      if (errno != EINTR)
-        pfatal_with_name (_("pselect jobs pipe"));
-      return 0;
-    }
+      fd_set readfds;
+      int r;
+      char intake;
 
-  if (r == 0)
-    /* Timeout.  */
-    return 0;
+      FD_ZERO (&readfds);
+      FD_SET (job_fds[0], &readfds);
 
-  /* The read FD is ready: read it!  */
-  EINTRLOOP (r, read (job_fds[0], &intake, 1));
-  if (r < 0)
-    pfatal_with_name (_("read jobs pipe"));
+      r = pselect (job_fds[0]+1, &readfds, NULL, NULL, specp, &empty);
+      if (r < 0)
+        switch (errno)
+          {
+          case EINTR:
+            /* SIGCHLD will show up as an EINTR.  */
+            return 0;
+
+          case EBADF:
+            /* Someone closed the jobs pipe.
+               That shouldn't happen but if it does we're done.  */
+              O (fatal, NILF, _("job server shut down"));
+ 
+          default:
+            pfatal_with_name (_("pselect jobs pipe"));
+          }
+
+      if (r == 0)
+        /* Timeout.  */
+        return 0;
+
+      /* The read FD is ready: read it!  This is non-blocking.  */
+      EINTRLOOP (r, read (job_fds[0], &intake, 1));
+
+      if (r < 0)
+        {
+          /* Someone sniped our token!  Try again.  */
+          if (errno == EAGAIN)
+            continue;
+
+          pfatal_with_name (_("read jobs pipe"));
+        }
 
-  /* What does it mean if read() returns 0?  It shouldn't happen because only
-     the master make can reap all the tokens and close the write side...??  */
-  return r > 0;
+      /* read() should never return 0: only the master make can reap all the
+         tokens and close the write side...??  */
+      return r > 0;
+    }
 }
 
 #else
