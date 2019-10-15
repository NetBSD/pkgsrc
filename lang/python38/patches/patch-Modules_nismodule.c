$NetBSD: patch-Modules_nismodule.c,v 1.1 2019/10/15 16:50:11 adam Exp $

DragonFlyBSD support
http://bugs.python.org/issue21459

--- Modules/nismodule.c.orig	2010-08-19 09:03:03.000000000 +0000
+++ Modules/nismodule.c
@@ -85,7 +85,7 @@ nis_mapname (char *map, int *pfix)
     return map;
 }
 
-#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
 typedef int (*foreachfunc)(unsigned long, char *, int, char *, int, void *);
 #else
 typedef int (*foreachfunc)(int, char *, int, char *, int, char *);
