$NetBSD: patch-src_w__keyboard.c,v 1.2 2017/10/04 11:58:45 wiz Exp $

Remove unportable header.
https://sourceforge.net/p/mcj/tickets/16/

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
