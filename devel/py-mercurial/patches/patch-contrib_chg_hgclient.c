$NetBSD: patch-contrib_chg_hgclient.c,v 1.1 2024/06/24 09:05:18 jperkin Exp $

Support systems that lack O_DIRECTORY.

--- contrib/chg/hgclient.c.orig	2024-06-24 09:00:13.361836008 +0000
+++ contrib/chg/hgclient.c
@@ -26,6 +26,10 @@
 #include "procutil.h"
 #include "util.h"
 
+#ifndef O_DIRECTORY
+#define O_DIRECTORY	O_RDONLY
+#endif
+
 enum {
 	CAP_GETENCODING = 0x0001,
 	CAP_RUNCOMMAND = 0x0002,
