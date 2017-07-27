$NetBSD: patch-scheduler-main.c,v 1.1 2017/07/27 08:54:26 wiz Exp $

Add a PidFile configuration directive to write a PID file.

--- scheduler/main.c.orig	2017-03-28 20:26:53.000000000 +0200
+++ scheduler/main.c	2017-07-17 18:02:10.000000000 +0200
@@ -72,6 +72,7 @@ static void		service_checkin(void);
 static void		service_checkout(void);
 #endif /* HAVE_ONDEMAND */
 static void		usage(int status) __attribute__((noreturn));
+static int		create_pidfile(const char *path);
 
 
 /*
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
 
@@ -1129,6 +1137,7 @@ main(int  argc,				/* I - Number of comm
                   "Scheduler shutting down due to program error.");
   }
 
+fail:
  /*
   * Close all network clients...
   */
@@ -1152,6 +1161,12 @@ main(int  argc,				/* I - Number of comm
 
   cupsdFreeAllJobs();
 
+ /*
+  * Remove pidfile...
+  */
+  if (PidFile && *PidFile)
+    (void)unlink(PidFile);
+
 #ifdef __APPLE__
  /*
   * Stop monitoring system event monitoring...
@@ -2035,6 +2050,36 @@ service_checkout(void)
 
 
 /*
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
+/*
  * 'usage()' - Show scheduler usage.
  */
 
