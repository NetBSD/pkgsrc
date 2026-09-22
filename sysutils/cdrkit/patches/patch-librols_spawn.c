$NetBSD: patch-librols_spawn.c,v 1.1 2026/09/22 08:05:41 ryoon Exp $

--- librols/spawn.c.orig	2026-08-22 08:55:54.265515333 +0000
+++ librols/spawn.c
@@ -44,6 +44,7 @@
 #include <vadefs.h>
 #include <waitdefs.h>
 #include <errno.h>
+#include <sys/wait.h>
 
 #define	MAX_F_ARGS	16
 
