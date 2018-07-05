$NetBSD: patch-src_posix_error.c,v 1.1 2018/07/05 14:24:38 jperkin Exp $

Missing strerror_l workaround for SunOS.

--- src/posix/error.c.orig	2014-08-14 07:20:04.000000000 +0000
+++ src/posix/error.c
@@ -31,6 +31,9 @@
 
 static const char *vlc_strerror_l(int errnum, const char *lname)
 {
+#ifdef __sun
+    const char *buf = strerror(errnum);
+#else
     int saved_errno = errno;
     locale_t loc = newlocale(LC_MESSAGES_MASK, lname, (locale_t)0);
 
@@ -51,6 +54,7 @@ static const char *vlc_strerror_l(int er
     const char *buf = strerror_l(errnum, loc);
 
     freelocale(loc);
+#endif
     return buf;
 }
 
