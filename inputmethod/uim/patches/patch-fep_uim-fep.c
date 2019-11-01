$NetBSD: patch-fep_uim-fep.c,v 1.1 2019/11/01 16:21:11 nia Exp $

Include missing header for tcgetattr

--- fep/uim-fep.c.orig	2017-08-14 00:07:26.000000000 +0000
+++ fep/uim-fep.c
@@ -109,6 +109,8 @@
 #include <libutil.h>
 #endif
 
+#include <termios.h>
+
 #include <uim/uim.h>
 
 #include "udsock.h"
