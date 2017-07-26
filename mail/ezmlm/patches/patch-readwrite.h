$NetBSD: patch-readwrite.h,v 1.2 2017/07/26 02:02:23 schmonz Exp $

Add some prototypes, missing headers and redefine log() to not conflict
with libm.

--- readwrite.h.orig	2013-02-25 16:49:34.000000000 +0000
+++ readwrite.h
@@ -1,7 +1,6 @@
 #ifndef READWRITE_H
 #define READWRITE_H
 
-extern int read();
-extern int write();
+#include <unistd.h>
 
 #endif
