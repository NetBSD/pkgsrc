$NetBSD: patch-libusal_scsi-remote.c,v 1.1 2026/09/22 08:05:41 ryoon Exp $

--- libusal/scsi-remote.c.orig	2026-08-22 08:57:08.575013941 +0000
+++ libusal/scsi-remote.c
@@ -74,6 +74,7 @@
 #include <unixstd.h>
 #include <strdefs.h>
 #include <schily.h>
+#include <sys/wait.h>
 
 #include <usal/usalcmd.h>
 #include <usal/scsitransp.h>
