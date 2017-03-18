$NetBSD: patch-memtrack.c,v 1.1 2017/03/18 13:54:24 adam Exp $

Don't include malloc.h; malloc() should be defined in stdlib.h.

--- memtrack.c.orig	2015-09-26 20:52:49.000000000 +0000
+++ memtrack.c
@@ -22,9 +22,6 @@
 
 #define _GNU_SOURCE
 
-#if !defined(SYS_FREEBSD)   /* FreeBSD declares malloc() in stdlib.h */
- #include <malloc.h>
-#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
