$NetBSD: patch-libntp_work__fork.c,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base; add support for setproctitle(3).

--- libntp/work_fork.c.orig	2019-03-09 08:15:34.000000000 +0000
+++ libntp/work_fork.c
@@ -434,6 +434,32 @@ fork_deferred_worker(void)
 }
 #endif
 
+#if HAVE_SETPROCTITLE == 0
+static void
+setproctitle(const char *fmt, ...)
+{
+	va_list ap;
+	char b1[128];
+	int argcc, argvlen, l;
+
+	if (saved_argc == 0)
+		return;
+
+	va_start(ap, fmt);
+	vsnprintf(b1, sizeof(b1), fmt, ap);
+	va_end(ap);
+
+	/* Clear argv */
+	for (argvlen = 0, argcc = 0; argcc < saved_argc; argcc++) {
+		l = strlen(saved_argv[argcc]);
+		argvlen += l + 1;
+		memset(saved_argv[argcc], 0, l);
+	}
+	l = snprintf(saved_argv[0], argvlen, "ntpd: %s", b1);
+	for (argcc = 1; argcc < saved_argc; argcc++)
+		saved_argv[argcc] = &saved_argv[0][l];
+}
+#endif
 
 static void
 fork_blocking_child(
@@ -545,17 +571,7 @@ fork_blocking_child(
 	 * Change the process name of the child to avoid confusion
 	 * about ntpd trunning twice.
 	 */
-	if (saved_argc != 0) {
-		int argcc;
-		int argvlen = 0;
-		/* Clear argv */
-		for (argcc = 0; argcc < saved_argc; argcc++) {
-			int l = strlen(saved_argv[argcc]);
-			argvlen += l + 1;
-			memset(saved_argv[argcc], 0, l);
-		}
-		strlcpy(saved_argv[0], "ntpd: asynchronous dns resolver", argvlen);
-	}
+	setproctitle("asynchronous dns resolver");
 
 	/*
 	 * In the child, close all files except stdin, stdout, stderr,
