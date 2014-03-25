$NetBSD: patch-source_highlight.c,v 1.2 2014/03/25 12:54:22 gdt Exp $

Silence gcc warnings about unsafe pointer casts.

--- source/highlight.c.orig	2004-08-01 10:06:10.000000000 +0000
+++ source/highlight.c
@@ -50,6 +50,7 @@ static const char CVSID[] = "$Id: highli
 #include <math.h>
 #include <stdlib.h>
 #include <string.h>
+#include <stdint.h>
 #ifdef VMS
 #include "../util/VMSparam.h"
 #else
@@ -510,7 +511,7 @@ void* GetHighlightInfo(WindowInfo *windo
     if (!pattern) {
 	return NULL;
     }
-    return (void*)pattern->userStyleIndex;    
+    return (void*)(intptr_t)pattern->userStyleIndex;    
 }
     
 /*
