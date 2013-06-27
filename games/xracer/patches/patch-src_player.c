$NetBSD: patch-src_player.c,v 1.1 2013/06/27 15:49:43 joerg Exp $

--- src/player.c.orig	2013-06-26 22:51:40.000000000 +0000
+++ src/player.c
@@ -20,6 +20,7 @@
 #include "config.h"
 
 #include <stdio.h>
+#include <string.h>
 #include <stdlib.h>
 
 #include "xracer.h"
