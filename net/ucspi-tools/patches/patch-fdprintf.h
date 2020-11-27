$NetBSD: patch-fdprintf.h,v 1.1 2020/11/27 11:34:17 schmonz Exp $

Not all systems have dprintf().

--- fdprintf.h.orig	2020-11-27 11:04:59.176728537 +0000
+++ fdprintf.h
@@ -0,0 +1,6 @@
+#ifndef FDPRINTF_H
+#define FDPRINTF_H
+
+int fdprintf(int, const char *, ...);
+
+#endif
