$NetBSD: patch-scheduler-main.c,v 1.5 2026/04/19 14:52:23 wiz Exp $

Add a PidFile configuration directive to write a PID file.

--- scheduler/main.c.orig	2026-04-17 12:22:45.000000000 +0000
+++ scheduler/main.c
@@ -63,6 +63,7 @@
  * Local functions...
  */
 
+static int		create_pidfile(const char *path);
 static void		parent_handler(int sig);
 static void		process_children(void);
 static void		sigchld_handler(int sig);
@@ -673,6 +674,13 @@ main(int  argc,				/* I - Number of command-line args 
 #endif /* __APPLE__ */
 
  /*
+  * Create pidfile...
+  */
+  if (PidFile && *PidFile)
+    if (!create_pidfile(PidFile))
+      goto fail;
+
+ /*
   * Send server-started event...
   */
 
@@ -1164,6 +1172,7 @@ main(int  argc,				/* I - Number of command-line args 
                   "Scheduler shutting down due to program error.");
   }
 
+fail:
  /*
   * Close all network clients...
   */
@@ -1189,6 +1198,12 @@ main(int  argc,				/* I - Number of command-line args 
   */
 
   cupsdDeleteTemporaryPrinters(1);
+ 
+/*
+ * Remove pidfile...
+ */
+ if (PidFile && *PidFile)
+   (void)unlink(PidFile);
 
 #ifdef __APPLE__
  /*
@@ -2136,6 +2151,36 @@ service_checkout(int shutdown)          /* I - Shuttin
   if (OnDemand && shutdown)
     xpc_transaction_end();
 #  endif /* __APPLE__ */
+}
+
+
+/*
+ * 'create_pidfile()' - Create PID file.
+ */
+static int
+create_pidfile(const char *path)
+{
+  int fd;
+  size_t l;
+  char s[42];
+  if ((l = snprintf(s, sizeof(s), "%jd\n", (intmax_t)getpid())) < 0) {
+    cupsdLogMessage(CUPSD_LOG_EMERG, "PidFile: snprintf() failed - %s!",
+                    strerror(errno));
+    return (0);
+  }
+  if ((fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0) {
+    cupsdLogMessage(CUPSD_LOG_EMERG, "PidFile: open(%s) failed - %s!",
+                    path, strerror(errno));
+    return (0);
+  }
+  if (write(fd, s, l + 1) < l + 1) {
+    cupsdLogMessage(CUPSD_LOG_EMERG, "PidFile %s: write(\"%s\", %zd) failed - %s!",
+                    path, s, l + 1, strerror(errno));
+    (void)close(fd);
+    return (0);
+  }
+  (void)close(fd);
+  return (1);
 }
 
 
