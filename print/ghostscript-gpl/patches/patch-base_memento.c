$NetBSD: patch-base_memento.c,v 1.1 2015/08/11 18:16:50 wiz Exp $

Rely on header to get memset prototype.

--- base/memento.c.orig	2012-08-08 08:01:36.000000000 +0000
+++ base/memento.c
@@ -40,11 +40,7 @@
 #ifdef MEMENTO_GS_HACKS
 /* For GS we include malloc_.h. Anyone else would just include memento.h */
 #include "malloc_.h"
-#ifdef __MACH__
 #include <string.h>
-#else
-void *memset(void *,int,size_t);
-#endif
 int atexit(void (*)(void));
 #else
 #include "memento.h"
