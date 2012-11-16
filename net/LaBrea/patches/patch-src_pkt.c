$NetBSD: patch-src_pkt.c,v 1.1 2012/11/16 20:10:21 joerg Exp $

--- src/pkt.c.orig	2003-09-12 21:23:39.000000000 +0000
+++ src/pkt.c
@@ -38,8 +38,8 @@
 #include <stdlib.h>
 #include <string.h>
 
-#include "bget.h"
-#include "pkt.h"
+#include "../inc/bget.h"
+#include "../inc/pkt.h"
 
 void
 pkt_init(int size)
