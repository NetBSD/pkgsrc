$NetBSD: patch-scheduler-main.c,v 1.2 2017/09/03 11:30:54 leot Exp $

Add a PidFile configuration directive to write a PID file.

--- scheduler/main.c.orig	2017-06-30 15:44:38.000000000 +0000
+++ scheduler/main.c
@@ -72,6 +72,7 @@ static void		service_checkin(void);
 static void		service_checkout(void);
 #endif /* HAVE_ONDEMAND */
 static void		usage(int status) __attribute__((noreturn));
+static int		create_pidfile(const char *path);
 
 
 /*
@@ -677,6 +678,13 @@ main(int  argc,				/* I - Number of comm
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
 
@@ -1139,6 +1147,7 @@ main(int  argc,				/* I - Number of comm
                   "Scheduler shutting down due to program error.");
   }
 
+fail:
  /*
   * Close all network clients...
   */
@@ -1167,6 +1176,12 @@ main(int  argc,				/* I - Number of comm
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
@@ -2068,6 +2083,36 @@ service_checkout(void)
 
 
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
 
