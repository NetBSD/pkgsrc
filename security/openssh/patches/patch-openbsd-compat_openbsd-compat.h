$NetBSD: patch-openbsd-compat_openbsd-compat.h,v 1.4 2016/01/18 12:53:26 jperkin Exp $

strtoll() declaration

--- openbsd-compat/openbsd-compat.h.orig	2015-08-21 04:49:03.000000000 +0000
+++ openbsd-compat/openbsd-compat.h
@@ -99,6 +99,10 @@ size_t strlcat(char *dst, const char *sr
 int setenv(register const char *name, register const char *value, int rewrite);
 #endif
 
+#ifndef HAVE_STRTOLL
+long long strtoll(const char *, char **, int);
+#endif
+
 #ifndef HAVE_STRMODE
 void strmode(int mode, char *p);
 #endif
