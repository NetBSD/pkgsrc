$NetBSD: patch-extcap.c,v 1.3 2016/10/09 21:13:22 wiz Exp $

Fix linking on NetBSD.
https://bugs.wireshark.org/bugzilla/show_bug.cgi?id=12883

--- extcap.c.orig	2016-10-04 18:27:54.000000000 +0000
+++ extcap.c
@@ -35,6 +35,8 @@
 #else
 /* Include for unlink */
 #include <unistd.h>
+/* for WEXITSTATUS */
+#include <sys/wait.h>
 #endif
 
 #ifdef HAVE_SYS_TYPES_H
