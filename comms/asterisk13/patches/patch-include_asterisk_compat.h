$NetBSD: patch-include_asterisk_compat.h,v 1.1.1.1 2015/12/05 23:29:10 jnemeth Exp $

--- include/asterisk/compat.h.orig	2015-10-09 21:48:48.000000000 +0000
+++ include/asterisk/compat.h
@@ -68,7 +68,7 @@
 #endif
 
 #ifndef AST_POLL_COMPAT
-#include <sys/poll.h>
+#include <poll.h>
 #else
 #include "asterisk/poll-compat.h"
 #endif
