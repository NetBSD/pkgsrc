$NetBSD: patch-portsentry.h,v 1.1 2026/03/17 07:26:47 nia Exp $

Fix implicit declaration of bzero in portsentry_io.c.

--- portsentry.h.orig	2026-03-17 07:12:03.970697405 +0000
+++ portsentry.h
@@ -29,6 +29,7 @@
 #include <time.h>
 #include <netdb.h>
 #include <string.h>
+#include <strings.h>
 #include <ctype.h>
 #include <errno.h>
 #include <stdarg.h>
