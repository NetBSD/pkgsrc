$NetBSD: patch-lib9_wait.c,v 1.1 2015/04/25 19:58:32 dholland Exp $

Remove bogus extra include.

--- lib9/wait.c~	2000-02-11 17:04:15.000000000 +0000
+++ lib9/wait.c
@@ -5,8 +5,6 @@
 #include <sys/resource.h>
 #include <sys/wait.h>
 
-#include "/usr/include/sys/wait.h"
-
 int
 __waitcommon(int pid, int status, struct rusage *rusage, Waitmsg *w) {
 	long utime, stime;
