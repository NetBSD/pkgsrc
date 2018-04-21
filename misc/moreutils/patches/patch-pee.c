$NetBSD: patch-pee.c,v 1.1 2018/04/21 17:27:51 leot Exp $

Needed for signal(3).

--- pee.c.orig	2017-12-31 16:02:11.000000000 +0000
+++ pee.c
@@ -1,6 +1,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <unistd.h>
+#include <signal.h>
 #include <string.h>
 #include <sys/types.h>
 #include <sys/wait.h>
