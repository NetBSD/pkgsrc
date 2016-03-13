$NetBSD: patch-pingmon_poll__sites.c,v 1.1 2016/03/13 09:06:01 dholland Exp $

Use standard headers.

--- pingmon/poll_sites.c~	1998-08-31 14:44:48.000000000 +0000
+++ pingmon/poll_sites.c
@@ -76,6 +76,7 @@
 
 #include "pingmon.h"
 
+#include <string.h>
 #include <signal.h>
 #include <sys/file.h>
 
