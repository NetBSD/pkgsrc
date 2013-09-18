$NetBSD: patch-nix_machine.h,v 1.1 2013/09/18 20:58:36 asau Exp $

--- nix/machine.h.orig	1995-01-12 07:45:22.000000000 +0000
+++ nix/machine.h
@@ -19,6 +19,7 @@
 	HA *nix specific include file
 ***********************************************************************/
 
+#include <string.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/stat.h>
