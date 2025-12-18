$NetBSD: patch-unix2dos.c,v 1.1 2025/12/18 12:57:48 nia Exp $

Add missing include for exit(3).

--- unix2dos.c.orig	2001-05-22 23:58:39.000000000 +0000
+++ unix2dos.c
@@ -1,4 +1,5 @@
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 #include <sys/types.h>
