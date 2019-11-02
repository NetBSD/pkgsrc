$NetBSD: patch-Engine_linevent.c,v 1.3 2019/11/02 22:25:46 mrg Exp $

Add NetBSD and DragonFlyBSD support.

--- Engine/linevent.c.orig	2014-01-07 08:54:20.000000000 -0800
+++ Engine/linevent.c	2014-02-12 23:45:21.000000000 -0800
@@ -27,7 +27,7 @@
 #include "linevent.h"
 
 #ifdef PIPES
-# if defined(SGI) || defined(LINUX) || defined(NeXT) || defined(__MACH__)
+# if defined(SGI) || defined(LINUX) || defined(NeXT) || defined(__MACH__) || defined(__NetBSD__) || defined(__DragonFly__)
 #  define _popen popen
 #  define _pclose pclose
 # elif defined(__BEOS__) ||  defined(__HAIKU__) || defined(__MACH__)
