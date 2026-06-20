$NetBSD: patch-src_cmd__search.c,v 1.1 2026/06/20 10:44:28 nia Exp $

Need to include <strings.h> for bzero(3).

--- src/cmd_search.c.orig	2026-06-20 10:41:50.187803127 +0000
+++ src/cmd_search.c
@@ -27,6 +27,7 @@ Foundation, Inc., 59 Temple Place, Suite 330, Boston, 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 #include <unistd.h>
 #include <signal.h>
 #include <sys/types.h>
