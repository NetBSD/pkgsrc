$NetBSD: patch-config.def.h,v 1.1 2024/07/18 13:25:36 ktnb Exp $

NetBSD also uses util.h. https://github.com/deadpixi/mtm/pull/78

--- config.def.h.orig	2024-07-18 00:58:43.999974063 +0000
+++ config.def.h
@@ -71,7 +71,7 @@
 
 /* Includes needed to make forkpty(3) work. */
 #ifndef FORKPTY_INCLUDE_H
-    #if defined(__APPLE__) || defined(__OpenBSD__)
+    #if defined(__APPLE__) || defined(__OpenBSD__) || defined(__NetBSD__)
         #define FORKPTY_INCLUDE_H <util.h>
     #elif defined(__FreeBSD__)
         #define FORKPTY_INCLUDE_H <libutil.h>
