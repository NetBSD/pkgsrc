$NetBSD: patch-pc.h,v 1.1 2013/03/03 01:06:51 joerg Exp $

--- pc.h.orig	2013-03-02 23:49:59.000000000 +0000
+++ pc.h
@@ -23,11 +23,6 @@
 extern int DebugLevel;
 #define IF_DEBUG(level, action) if (DebugLevel >= level) { action; }
 
-// bool type might not be available everywhere
-#if (SIZEOF_BOOL == 0)
-typedef enum {false, true} bool;
-#endif /* SIZEOF_BOOL */
-
 // Mode types
 typedef enum {
     ModeNone,
