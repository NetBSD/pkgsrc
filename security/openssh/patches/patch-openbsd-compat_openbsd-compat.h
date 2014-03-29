$NetBSD: patch-openbsd-compat_openbsd-compat.h,v 1.2 2014/03/29 09:38:11 taca Exp $

strtoll() declaration

--- openbsd-compat/openbsd-compat.h.orig	2014-02-04 00:18:23.000000000 +0000
+++ openbsd-compat/openbsd-compat.h
@@ -84,6 +84,10 @@ size_t strlcat(char *dst, const char *sr
 int setenv(register const char *name, register const char *value, int rewrite);
 #endif
 
+#ifndef HAVE_STRTOLL
+long long strtoll(const char *, char **, int);
+#endif
+
 #ifndef HAVE_STRMODE
 void strmode(int mode, char *p);
 #endif
