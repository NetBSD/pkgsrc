$NetBSD: patch-sockets.c,v 1.1 2026/03/22 09:41:31 nia Exp $

Fix implicit function declaration.

--- sockets.c.orig	2026-03-22 09:24:31.574607613 +0000
+++ sockets.c
@@ -36,6 +36,8 @@ Bool errorMessageFromReadExact = True;
 Bool useSSHTunnel;
 char *useSSHGateway;
 
+int tunnel(char *, char *, int);
+
 /*
  * Read an exact number of bytes, and don't return until you've got them.
  */
