$NetBSD: patch-src_mpeg_store.c,v 1.1 2013/06/27 15:49:43 joerg Exp $

--- src/mpeg/store.c.orig	2013-06-26 22:53:12.000000000 +0000
+++ src/mpeg/store.c
@@ -31,6 +31,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 
 #include "mpeg-config.h"
 #include "global.h"
