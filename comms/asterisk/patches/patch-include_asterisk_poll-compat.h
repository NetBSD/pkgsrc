$NetBSD: patch-include_asterisk_poll-compat.h,v 1.1 2015/10/27 08:49:01 jnemeth Exp $

--- include/asterisk/poll-compat.h.orig	2015-10-09 22:23:39.000000000 +0000
+++ include/asterisk/poll-compat.h
@@ -83,7 +83,7 @@
 
 #ifndef AST_POLL_COMPAT
 
-#include <sys/poll.h>
+#include <poll.h>
 
 #define ast_poll(a, b, c) poll(a, b, c)
 
