$NetBSD: patch-lib_selfpipe.cc,v 1.2 2017/10/28 04:51:06 schmonz Exp $

Add missing include.

--- lib/selfpipe.cc.orig	2017-02-17 10:54:28.240596810 +0000
+++ lib/selfpipe.cc
@@ -20,6 +20,7 @@
 // <nullmailer-subscribe@lists.untroubled.org>.
 
 #include <sys/types.h>
+#include <sys/time.h>
 #include <errno.h>
 #include <fcntl.h>
 #include <signal.h>
