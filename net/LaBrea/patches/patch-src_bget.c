$NetBSD: patch-src_bget.c,v 1.1 2012/11/16 20:10:20 joerg Exp $

--- src/bget.c.orig	2003-09-09 20:55:03.000000000 +0000
+++ src/bget.c
@@ -468,7 +468,7 @@ extern char *sprintf();               /*
 /*  Declare the interface, including the requested buffer size type,
     bufsize.  */
 
-#include "bget.h"
+#include "../inc/bget.h"
 
 #define MemSize     int 	      /* Type for size arguments to memxxx()
 					 functions such as memcmp(). */
