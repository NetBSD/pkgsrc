$NetBSD: patch-openbsd-compat_openbsd-compat.h,v 1.1 2013/05/01 19:58:26 imil Exp $

strtoll() declaration

--- openbsd-compat/openbsd-compat.h.orig	2013-02-15 01:20:42.000000000 +0000
+++ openbsd-compat/openbsd-compat.h
@@ -83,6 +83,10 @@ size_t strlcat(char *dst, const char *sr
 int setenv(register const char *name, register const char *value, int rewrite);
 #endif
 
+#ifndef HAVE_STRTOLL
+long long strtoll(const char *, char **, int);
+#endif
+
 #ifndef HAVE_STRMODE
 void strmode(int mode, char *p);
 #endif
