$NetBSD: patch-lib_ivykis_src_iv__fd__port.c,v 1.1 2015/10/29 16:34:13 fhajny Exp $

Need sys/poll.h on SunOS.

--- lib/ivykis/src/iv_fd_port.c.orig	2014-12-15 14:49:36.000000000 +0000
+++ lib/ivykis/src/iv_fd_port.c
@@ -23,6 +23,9 @@
 #include <fcntl.h>
 #include <port.h>
 #include <string.h>
+#ifdef __sun
+#include <sys/poll.h>
+#endif
 #include "iv_private.h"
 #include "iv_fd_private.h"
 
