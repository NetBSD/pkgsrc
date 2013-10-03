$NetBSD: patch-fdm.h,v 1.2 2013/10/03 11:12:43 obache Exp $

MAXNAMLEN is not POSIX. For systems that does not define it use NAME_MAX
macro instead.

--- fdm.h.orig	2011-10-10 13:36:29.000000000 +0000
+++ fdm.h
@@ -76,6 +76,10 @@
 
 extern char	*__progname;
 
+#ifndef MAXNAMLEN
+#define MAXNAMLEN NAME_MAX
+#endif
+
 /* Linux compatibility bullshit. */
 #ifndef UID_MAX
 #define UID_MAX UINT_MAX
