$NetBSD: patch-diff_util.c,v 1.1 2025/04/29 09:10:51 tnn Exp $

* replace K&R prototype

--- diff/util.c.orig	2025-04-29 08:59:30.153087345 +0000
+++ diff/util.c
@@ -24,7 +24,7 @@ GNU General Public License for more deta
 #endif
 
 #ifndef strerror
-extern char *strerror ();
+extern char *strerror (int);
 #endif
 
 /* Queue up one-line messages to be printed at the end,
