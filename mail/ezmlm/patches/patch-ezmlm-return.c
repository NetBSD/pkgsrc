$NetBSD: patch-ezmlm-return.c,v 1.2 2017/07/26 02:02:23 schmonz Exp $

Add some prototypes, missing headers and redefine log() to not conflict
with libm.

--- ezmlm-return.c.orig	2013-02-25 16:48:52.000000000 +0000
+++ ezmlm-return.c
@@ -17,6 +17,7 @@
 #include "cookie.h"
 #include "subscribe.h"
 #include "issub.h"
+#include "log.h"
 
 #define FATAL "ezmlm-return: fatal: "
 void die_usage() { strerr_die1x(100,"ezmlm-return: usage: ezmlm-return dir"); }
