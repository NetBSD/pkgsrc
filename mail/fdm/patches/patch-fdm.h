$NetBSD: patch-fdm.h,v 1.3 2015/09/25 13:08:44 leot Exp $

MAXNAMLEN is not POSIX. For systems that does not define it use NAME_MAX
macro instead.

--- fdm.h.orig	2015-09-14 14:40:44.000000000 +0000
+++ fdm.h
@@ -72,6 +72,10 @@
 
 extern char	*__progname;
 
+#ifndef MAXNAMLEN
+#define MAXNAMLEN NAME_MAX
+#endif
+
 /* Linux compatibility bullshit. */
 #ifndef UID_MAX
 #define UID_MAX UINT_MAX
