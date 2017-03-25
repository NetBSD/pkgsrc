$NetBSD: patch-TraceScreen.c,v 1.1 2017/03/25 10:53:59 maya Exp $

Add missing include

--- TraceScreen.c.orig	2016-05-26 00:37:01.000000000 +0000
+++ TraceScreen.c
@@ -22,6 +22,7 @@ in the source distribution for its full 
 #include <stdbool.h>
 #include <unistd.h>
 #include <fcntl.h>
+#include <sys/time.h>
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <signal.h>
