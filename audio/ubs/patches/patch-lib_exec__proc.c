$NetBSD: patch-lib_exec__proc.c,v 1.1 2026/06/20 10:44:28 nia Exp $

Need to include <strings.h> for bzero(3).

--- lib/exec_proc.c.orig	2026-06-20 10:41:16.472407774 +0000
+++ lib/exec_proc.c
@@ -24,6 +24,7 @@ Foundation, Inc., 59 Temple Place, Suite 330, Boston, 
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
+#include <strings.h>
 #include <signal.h>
 #include <errno.h>
 #include <sys/types.h>
