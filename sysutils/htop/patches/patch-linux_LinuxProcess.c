$NetBSD: patch-linux_LinuxProcess.c,v 1.1 2021/03/15 22:23:59 fox Exp $

Remove Linux only headers.

--- linux/LinuxProcess.c.orig	2021-03-15 09:16:51.679521216 +0000
+++ linux/LinuxProcess.c
@@ -12,7 +12,6 @@ in the source distribution for its full 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <syscall.h>
 #include <unistd.h>
 
 #include "CRT.h"
