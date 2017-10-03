$NetBSD: patch-src_w__keyboard.c,v 1.1 2017/10/03 15:09:36 wiz Exp $

Remove unportable header.

--- src/w_keyboard.c.orig	2016-07-23 21:10:28.000000000 +0000
+++ src/w_keyboard.c
@@ -18,9 +18,6 @@
 
 #include <sys/types.h>
 #include <regex.h>
-#ifndef __FreeBSD__
-#include <alloca.h>
-#endif
 #include <string.h>
 
 #include "fig.h"
