$NetBSD: patch-async_daemonize.C,v 1.1 2017/09/09 19:45:46 dholland Exp $

Clean up %m abuse.

--- async/daemonize.C~	2009-02-12 13:20:42.000000000 +0000
+++ async/daemonize.C
@@ -21,6 +21,7 @@
  *
  */
 
+#include <cstring>
 #include "async.h"
 
 str syslog_priority ("daemon.notice");
@@ -31,7 +32,7 @@ start_log_to_file (const str &line, cons
   int fd;
   int n;
   if ((fd = open (logfile.cstr (), flags, m)) < 0) {
-    warn ("%s: %m\n", logfile.cstr ());
+    warn ("%s: %s\n", logfile.cstr (), strerror(errno));
     fd = errfd;
   } else {
     warn << "Logging via logfile: " << logfile << "\n";
@@ -65,7 +66,7 @@ start_logger (const str &priority, const
   pid_t pid;
   int status;
   if ((pid = spawn (PATH_LOGGER, av, 0, 0, errfd)) < 0) {
-    warn ("%s: %m\n", PATH_LOGGER);
+    warn ("%s: %s\n", PATH_LOGGER, strerror(errno));
     return start_log_to_file (line, logfile, flags, mode);
   } 
   if (waitpid (pid, &status, 0) <= 0 || !WIFEXITED (status) || 
@@ -74,7 +75,7 @@ start_logger (const str &priority, const
 
   int fds[2];
   if (socketpair (AF_UNIX, SOCK_STREAM, 0, fds) < 0)
-    fatal ("socketpair: %m\n");
+    fatal ("socketpair: %s\n", strerror(errno));
   close_on_exec (fds[0]);
   if (fds[1] != 0)
     close_on_exec (fds[1]);
@@ -84,7 +85,7 @@ start_logger (const str &priority, const
     close (fds[1]);
     return fds[0];
   } else 
-    warn ("%s: %m\n", PATH_LOGGER);
+    warn ("%s: %s\n", PATH_LOGGER, strerror(errno));
 #endif /* PATH_LOGGER */
   return start_log_to_file (line, logfile, flags, mode);
 }
@@ -103,7 +104,7 @@ start_logger ()
     close (fd);
 
   if (socketpair (AF_UNIX, SOCK_STREAM, 0, fds) < 0)
-    fatal ("socketpair: %m\n");
+    fatal ("socketpair: %s\n", strerror(errno));
   close_on_exec (fds[0]);
   if (fds[1] != 0)
     close_on_exec (fds[1]);
@@ -113,7 +114,7 @@ start_logger ()
     if (fds[0] != errfd) {
       err_flush ();		// XXX - we shouldn't depend on aerr.C
       if (dup2 (fds[0], errfd) < 0)
-	fatal ("dup2: %m\n");
+	fatal ("dup2: %s\n", strerror(errno));
       close (fds[0]);
     }
     if (errfd != 1)
@@ -121,7 +122,7 @@ start_logger ()
     return;
   }
   else
-    warn ("%s: %m\n", PATH_LOGGER);
+    warn ("%s: %s\n", PATH_LOGGER, strerror(errno));
 #endif /* PATH_LOGGER */
   
   /* No logger, at least send chatter to stdout rather than stderr, so
@@ -161,13 +162,13 @@ daemonize (const str &nm)
   default:
     _exit (0);
   case -1:
-    fatal ("fork: %m\n");
+    fatal ("fork: %s\n", strerror(errno));
   case 0:
     break;
   }
     
   if (setsid () == -1)
-    fatal ("setsid: %m\n");
+    fatal ("setsid: %s\n", strerror(errno));
   if (!builddir) {
     start_logger ();
     str path = strbuf () << PIDDIR << "/" << pidfilebase << ".pid";
