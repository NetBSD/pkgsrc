$NetBSD: patch-src_newhash.c,v 1.1 2016/01/17 15:14:47 joerg Exp $

--- src/newhash.c.orig	2016-01-16 13:48:20.000000000 +0000
+++ src/newhash.c
@@ -21,6 +21,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include "l_defs.h"
 
 static hash *IL_NULL_hash;
