$NetBSD: patch-modplug.c,v 1.1 2014/04/19 14:48:12 joerg Exp $

--- modplug.c.orig	2014-04-19 13:01:44.000000000 +0000
+++ modplug.c
@@ -24,7 +24,7 @@
 #include "config/modplug.h"
 #endif
 
-#include <modplug.h>
+#include <libmodplug/modplug.h>
 #include <sys/types.h>
 #include <unistd.h>
 #include <stdlib.h>
