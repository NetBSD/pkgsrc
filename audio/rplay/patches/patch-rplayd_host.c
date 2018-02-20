$NetBSD: patch-rplayd_host.c,v 1.1 2018/02/20 08:35:52 dholland Exp $

Use standard headers.

--- rplayd/host.c~	1999-06-09 06:27:44.000000000 +0000
+++ rplayd/host.c
@@ -30,6 +30,7 @@
 #ifdef HAVE_STRING_H
 #include <string.h>
 #endif
+#include <time.h>
 #include "host.h"
 #include "buffer.h"
 #include "misc.h"
