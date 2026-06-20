$NetBSD: patch-src_loginfo.c,v 1.1 2026/06/20 10:44:28 nia Exp $

Need to include <strings.h> for bzero(3).

--- src/loginfo.c.orig	2026-06-20 10:41:43.691153776 +0000
+++ src/loginfo.c
@@ -28,6 +28,7 @@ Foundation, Inc., 59 Temple Place, Suite 330, Boston, 
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
+#include <strings.h>
 
 #include "ubs-main.h"
 
