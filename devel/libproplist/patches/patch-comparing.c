$NetBSD: patch-comparing.c,v 1.1 2026/01/20 08:18:09 wiz Exp $

Add header for memcmp() etc.

--- comparing.c.orig	2026-01-20 08:16:37.408163646 +0000
+++ comparing.c
@@ -5,6 +5,7 @@
    */
 
 #include "proplistP.h"
+#include <string.h>
 
 /* forward prototype */
 BOOL PLStrCmp(proplist_t pl1, proplist_t pl2);
