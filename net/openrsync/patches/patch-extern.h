$NetBSD: patch-extern.h,v 1.3 2025/11/30 11:46:38 vins Exp $

Add missing include.

--- extern.h.orig	2025-11-30 12:37:24.789764856 +0000
+++ extern.h
@@ -17,6 +17,7 @@
 #ifndef EXTERN_H
 #define EXTERN_H
 
+#include <stdint.h>
 #include "md4.h"
 
 #if !HAVE_PLEDGE
