$NetBSD: patch-highscore.cc,v 1.1 2017/02/18 14:00:54 joerg Exp $

--- highscore.cc.orig	2017-02-18 01:43:08.397167835 +0000
+++ highscore.cc
@@ -20,6 +20,7 @@
 #include "decl.h"
 #include "screen.h"
 
+#include <sys/stat.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
