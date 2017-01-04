$NetBSD: patch-ui.c,v 1.1 2017/01/04 22:26:02 roy Exp $

--- ui.c.orig	2017-01-04 21:58:51.719680033 +0000
+++ ui.c
@@ -12,6 +12,7 @@
 #include <sys/utsname.h>
 #include <pwd.h>
 #include <signal.h>
+#include <stdarg.h>
 #include <unistd.h>
 
 #include "mt.h"
