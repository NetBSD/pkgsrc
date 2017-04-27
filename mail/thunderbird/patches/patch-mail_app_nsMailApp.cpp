$NetBSD: patch-mail_app_nsMailApp.cpp,v 1.2 2017/04/27 13:32:40 ryoon Exp $

--- mail/app/nsMailApp.cpp.orig	2017-04-14 04:52:45.000000000 +0000
+++ mail/app/nsMailApp.cpp
@@ -14,6 +14,26 @@
 #include <sys/resource.h>
 #include <unistd.h>
 #endif
+/*
+ * On netbsd-4, ulimit -n is 64 by default; too few for us.
+ */
+static void netbsd_fixrlimit(void) {
+	struct rlimit rlp;
+	if (getrlimit(RLIMIT_NOFILE, &rlp) == -1) {
+		fprintf(stderr, "warning: getrlimit failed\n");
+		return;
+	}
+	if (rlp.rlim_cur >= 512)
+		return;
+	if (rlp.rlim_max < 512) {
+		fprintf(stderr, "warning: hard limit of 'ulimit -n' too low\n");
+		rlp.rlim_cur = rlp.rlim_max;
+	}
+	else
+		rlp.rlim_cur = 512;
+	if (setrlimit(RLIMIT_NOFILE, &rlp) == -1)
+		fprintf(stderr, "warning: setrlimit failed\n");
+	}
 
 #include <stdio.h>
 #include <stdarg.h>
@@ -261,6 +281,7 @@ FileExists(const char *path)
 static nsresult
 InitXPCOMGlue(const char *argv0, nsIFile **xreDirectory)
 {
+  netbsd_fixrlimit();
   char exePath[MAXPATHLEN];
 
   nsresult rv = mozilla::BinaryPath::Get(argv0, exePath);
