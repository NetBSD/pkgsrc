$NetBSD: patch-proc.h,v 1.2 2015/03/06 21:03:20 ryoon Exp $

Fix missing include

--- proc.h.orig	2015-02-16 19:07:12.000000000 +0000
+++ proc.h
@@ -17,6 +17,8 @@
 #include <sys/time.h>
 #include <list>
 
+#include <termios.h>
+
 #include "util.h"
 #include "io.h"
 #include "common.h"
