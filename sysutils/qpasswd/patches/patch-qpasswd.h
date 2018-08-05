$NetBSD: patch-qpasswd.h,v 1.1 2018/08/05 15:00:46 schmonz Exp $

Avoid Linuxisms.

--- qpasswd.h.orig	2004-01-13 16:10:18.000000000 +0000
+++ qpasswd.h
@@ -8,14 +8,13 @@
 #include <sys/time.h>
 #include <sys/stat.h>
 #include <sys/mman.h>
+#include <sys/wait.h>
 #include <unistd.h>
 #include <signal.h>
-#include <shadow.h>
 #include <string.h>
 #include <stdlib.h>
 #include <fcntl.h>
 #include <errno.h>
-#include <wait.h>
 #include <time.h>
 #include <grp.h>
 #include <pwd.h>
