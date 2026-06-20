$NetBSD: patch-src_read__sched.c,v 1.1 2026/06/20 10:44:28 nia Exp $

Need to include <strings.h> for bzero(3).

--- src/read_sched.c.orig	2026-06-20 10:41:30.968727908 +0000
+++ src/read_sched.c
@@ -28,6 +28,7 @@ Foundation, Inc., 59 Temple Place, Suite 330, Boston, 
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
+#include <strings.h>
 
 #include "ubs-sched.h"
 
