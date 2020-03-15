$NetBSD: patch-daemons_hw__default.c,v 1.1 2020/03/15 21:08:41 tnn Exp $

Add a missing include.

--- daemons/hw_default.c.orig	2011-03-25 22:28:18.000000000 +0000
+++ daemons/hw_default.c
@@ -21,6 +21,7 @@
 #include <limits.h>
 #include <signal.h>
 #include <sys/stat.h>
+#include <sys/sysmacros.h> /* for major() */
 #include <sys/types.h>
 #include <sys/ioctl.h>
 #include <sys/socket.h>
