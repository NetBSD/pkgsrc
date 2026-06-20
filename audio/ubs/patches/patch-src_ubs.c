$NetBSD: patch-src_ubs.c,v 1.1 2026/06/20 10:44:28 nia Exp $

Need to include <strings.h> for bzero(3).

--- src/ubs.c.orig	2026-06-20 10:41:37.098417440 +0000
+++ src/ubs.c
@@ -28,6 +28,7 @@ Foundation, Inc., 59 Temple Place, Suite 330, Boston, 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 #include <signal.h>
 #include <sys/types.h>
 
