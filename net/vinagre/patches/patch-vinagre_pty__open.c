$NetBSD: patch-vinagre_pty__open.c,v 1.3 2024/04/21 15:08:43 wiz Exp $

--- vinagre/pty_open.c.orig	2016-09-13 08:34:13.000000000 +0000
+++ vinagre/pty_open.c
@@ -41,7 +41,7 @@
 
 /* Originally from vte */
 
-#define _XOPEN_SOURCE
+#define _XOPEN_SOURCE 600
 #define _GNU_SOURCE
 #define _BSD_SOURCE
 
