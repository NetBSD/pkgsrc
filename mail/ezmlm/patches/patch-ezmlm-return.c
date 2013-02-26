$NetBSD: patch-ezmlm-return.c,v 1.1 2013/02/26 11:26:03 joerg Exp $

--- ezmlm-return.c.orig	2013-02-25 16:48:52.000000000 +0000
+++ ezmlm-return.c
@@ -17,6 +17,7 @@
 #include "cookie.h"
 #include "subscribe.h"
 #include "issub.h"
+#include "log.h"
 
 #define FATAL "ezmlm-return: fatal: "
 void die_usage() { strerr_die1x(100,"ezmlm-return: usage: ezmlm-return dir"); }
