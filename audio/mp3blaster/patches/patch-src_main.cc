$NetBSD: patch-src_main.cc,v 1.1 2012/01/11 19:20:13 hans Exp $

--- src/main.cc.orig	2009-01-24 16:25:10.000000000 +0100
+++ src/main.cc	2011-12-30 18:28:22.923387315 +0100
@@ -35,6 +35,7 @@
 #include "history.h"
 #include "mp3blaster.h"
 #include <string.h>
+#include <strings.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
