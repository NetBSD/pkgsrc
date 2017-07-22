$NetBSD: patch-include_irc.h,v 1.1 2017/07/22 15:13:41 maya Exp $

limits.h for PATH_MAX

--- include/irc.h.orig	2017-07-03 12:44:25.000000000 +0000
+++ include/irc.h
@@ -92,6 +92,7 @@
 # include <fcntl.h>
 #endif /* HAVE_FCNTL_H */
 
+#include <limits.h>
 #include <unistd.h>
 
 #ifdef HAVE_SYS_FILE_H
