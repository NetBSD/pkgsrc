$NetBSD: patch-logfile.c,v 1.1 2025/05/12 16:03:20 wiz Exp $

https://security.opensuse.org/2025/05/12/screen-security-issues.html

--- logfile.c.orig	2024-08-28 19:55:03.000000000 +0000
+++ logfile.c
@@ -88,10 +88,29 @@ static int logfile_reopen(char *name, in
 		return -1;
 	}
 	changed_logfile(l);
-	l->st->st_ino = l->st->st_dev = 0;
 	return 0;
 }
 
+static int (*lf_reopen_fn) (char *, int, struct Log *) = logfile_reopen;
+
+/*
+ * Whenever logfwrite discoveres that it is required to close and
+ * reopen the logfile, the function registered here is called.
+ * If you do not register anything here, the above logfile_reopen()
+ * will be used instead.
+ * Your function should perform the same steps as logfile_reopen():
+ * a) close the original filedescriptor without flushing any output
+ * b) open a new logfile for future output on the same filedescriptor number.
+ * c) zero out st_dev, st_ino to tell the stolen_logfile() indcator to
+ *    reinitialise itself.
+ * d) return 0 on success.
+ */
+void logreopen_register(int (*fn) (char *, int, struct Log *))
+{
+	lf_reopen_fn = fn ? fn : logfile_reopen;
+}
+
+
 /*
  * If the logfile has been removed, truncated, unlinked or the like,
  * return nonzero.
@@ -204,7 +223,7 @@ int logfwrite(Log *l, char *buf, size_t 
 {
 	int r;
 
-	if (stolen_logfile(l) && logfile_reopen(l->name, fileno(l->fp), l))
+	if (stolen_logfile(l) && lf_reopen_fn(l->name, fileno(l->fp), l))
 		return -1;
 	r = fwrite(buf, n, 1, l->fp);
 	l->writecount += l->flushcount + 1;
@@ -219,13 +238,13 @@ int logfflush(Log *l)
 
 	if (!l)
 		for (l = logroot; l; l = l->next) {
-			if (stolen_logfile(l) && logfile_reopen(l->name, fileno(l->fp), l))
+			if (stolen_logfile(l) && lf_reopen_fn(l->name, fileno(l->fp), l))
 				return -1;
 			r |= fflush(l->fp);
 			l->flushcount++;
 			changed_logfile(l);
 	} else {
-		if (stolen_logfile(l) && logfile_reopen(l->name, fileno(l->fp), l))
+		if (stolen_logfile(l) && lf_reopen_fn(l->name, fileno(l->fp), l))
 			return -1;
 		r = fflush(l->fp);
 		l->flushcount++;
