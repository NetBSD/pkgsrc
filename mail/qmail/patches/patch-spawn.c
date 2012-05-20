$NetBSD: patch-spawn.c,v 1.1 2012/05/20 08:48:56 marino Exp $

--- spawn.c.orig	2012-04-14 13:35:08.381341000 +0000
+++ spawn.c
@@ -1,5 +1,6 @@
 #include <sys/types.h>
 #include <sys/stat.h>
+#include "alloc.h"
 #include "sig.h"
 #include "wait.h"
 #include "substdio.h"
