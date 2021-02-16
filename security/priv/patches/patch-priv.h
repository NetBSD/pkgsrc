$NetBSD: patch-priv.h,v 1.1 2021/02/16 09:42:06 kim Exp $

Include login_cap.h for setusercontext(3), which is needed for per-user
tmp to work.

--- priv.h.orig	1997-07-08 06:19:07.000000000 +0000
+++ priv.h
@@ -89,6 +89,14 @@
 # endif
 #endif
 
+#ifdef HAVE_LOGIN_CAP_H
+# include <login_cap.h>
+#endif
+
+#ifdef HAVE_ERR_H
+# include <err.h>
+#endif
+
 #define DEFPATH		"/bin:/usr/bin"
 #define SYSLOGNAME	"priv"			/* name used with syslog */
 #define LOGBUFSIZ	2048 + 256		/* number of chars to log */
@@ -140,10 +148,10 @@ char   *strsep(char **, const char *);
 #ifndef HAVE_STRERROR
 char   *strerror(int errnum);
 #endif
-#ifdef HAVE_STRSPN
+#ifndef HAVE_STRSPN
 size_t  strspn(const char *s, const char *charset);
 #endif
-#ifdef HAVE_STRTOUL
+#ifndef HAVE_STRTOUL
 unsigned long strtoul(const char *nptr, char **endptr, int base);
 #endif
 
