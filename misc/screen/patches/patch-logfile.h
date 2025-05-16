$NetBSD: patch-logfile.h,v 1.1.2.2 2025/05/16 14:14:45 maya Exp $

https://security.opensuse.org/2025/05/12/screen-security-issues.html

--- logfile.h.orig	2024-08-28 19:55:03.000000000 +0000
+++ logfile.h
@@ -72,6 +72,16 @@ int logfwrite (Log *, char *, size_t);
 int logfflush (Log *ifany);
 
 /*
+ * a reopen function may be registered here, in case you want to bring your
+ * own (more secure open), it may come along with a private data pointer.
+ * this function is called, whenever logfwrite/logfflush detect that the
+ * file has been (re)moved, truncated or changed by someone else.
+ * if you provide NULL as parameter to logreopen_register, the builtin
+ * reopen function will be reactivated.
+ */
+void logreopen_register (int (*fn) (char *, int, struct Log *) );
+
+/*
  * Your custom reopen function is required to reuse the exact
  * filedescriptor.
  * See logfile.c for further specs and an example.
