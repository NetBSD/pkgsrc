$NetBSD: patch-src_zm__comms.h,v 1.1 2026/07/30 12:36:00 gdt Exp $

\todo Disable, reproduce error, and file upstream.

--- src/zm_comms.h.orig	2026-07-26 00:41:38.146240669 +0000
+++ src/zm_comms.h
@@ -26,6 +26,7 @@
 #include <cerrno>
 #include <netdb.h>
 #include <set>
+#include <strings.h>
 #include <sys/uio.h>
 #include <sys/un.h>
 #include <unistd.h>
