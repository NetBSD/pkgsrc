$NetBSD: patch-nbname.c,v 1.1 2026/03/21 09:42:00 nia Exp $

Need <strings.h> for bzero(3).

--- nbname.c.orig	2026-03-21 09:16:34.404281065 +0000
+++ nbname.c
@@ -23,6 +23,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 #include <unistd.h>
 #include <sys/stat.h>
 #include <sys/time.h>
