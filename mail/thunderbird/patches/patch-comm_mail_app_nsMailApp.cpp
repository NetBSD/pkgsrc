$NetBSD: patch-comm_mail_app_nsMailApp.cpp,v 1.1 2018/12/16 08:12:15 ryoon Exp $

--- comm/mail/app/nsMailApp.cpp.orig	2018-12-04 23:12:16.000000000 +0000
+++ comm/mail/app/nsMailApp.cpp
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
@@ -235,6 +255,7 @@ static int do_main(int argc, char* argv[
 static nsresult
 InitXPCOMGlue()
 {
+  netbsd_fixrlimit();
   UniqueFreePtr<char> exePath = BinaryPath::Get();
   if (!exePath) {
     Output("Couldn't find the application directory.\n");
