$NetBSD: patch-server_miniupnp_miniwget.c,v 1.1 2016/03/24 13:36:52 richard Exp $

If MIN() is undefined, just define one instead of including utility.h
on SunOS, which presumes a version of eti.h that has some extras over
what is provided in ncurses/eti.h, causing unnecessary build errors.

--- server/miniupnp/miniwget.c.orig	2011-02-23 20:29:05.000000000 +0000
+++ server/miniupnp/miniwget.c
@@ -26,9 +26,8 @@
 #include <arpa/inet.h>
 #define closesocket close
 #endif
-/* for MIN() macro : */
-#if defined(__sun) || defined(sun)
-#include <utility.h>
+#ifndef	MIN
+#define	MIN(x, y)	((x) < (y) ? (x) : (y))
 #endif
 
 /* miniwget2() :
