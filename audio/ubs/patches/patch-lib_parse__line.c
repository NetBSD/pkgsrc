$NetBSD: patch-lib_parse__line.c,v 1.1 2026/06/20 10:44:28 nia Exp $

Need to include <strings.h> for bzero(3).

--- lib/parse_line.c.orig	2026-06-20 10:41:24.094071299 +0000
+++ lib/parse_line.c
@@ -28,6 +28,7 @@ Foundation, Inc., 59 Temple Place, Suite 330, Boston, 
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
+#include <strings.h>
 
 #include "ubs-sched.h"
 
