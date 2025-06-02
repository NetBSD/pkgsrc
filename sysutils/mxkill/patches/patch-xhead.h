$NetBSD: patch-xhead.h,v 1.1 2025/06/02 11:16:24 vins Exp $

Do not require malloc.h

--- xhead.h.orig	2025-06-02 07:30:16.310224142 +0000
+++ xhead.h
@@ -26,7 +26,6 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-#include <malloc.h>
 #include <memory.h>
 #include <ctype.h>
 #include <string.h>
