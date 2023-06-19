$NetBSD: patch-scheduler-main.c,v 1.3 2023/06/19 19:28:36 schmonz Exp $

Add a PidFile configuration directive to write a PID file.

--- scheduler/main.c.orig	2023-06-06 12:55:36.000000000 +0000
+++ scheduler/main.c
@@ -63,6 +63,7 @@
  * Local functions...
  */
 
+static int		create_pidfile(const char *path);
 static void		parent_handler(int sig);
 static void		process_children(void);
 static void		sigchld_handler(int sig);
@@ -675,6 +676,13 @@ main(int  argc,				/* I - Number of comm
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
 
@@ -1166,6 +1174,7 @@ main(int  argc,				/* I - Number of comm
                   "Scheduler shutting down due to program error.");
   }
 
+fail:
  /*
   * Close all network clients...
   */
@@ -1191,6 +1200,12 @@ main(int  argc,				/* I - Number of comm
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
@@ -2126,6 +2141,36 @@ service_checkout(int shutdown)
 }
 
 
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
+}
+
+
 /*
  * 'usage()' - Show scheduler usage.
  */
