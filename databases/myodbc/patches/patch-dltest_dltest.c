$NetBSD: patch-dltest_dltest.c,v 1.1 2025/11/03 08:57:31 wiz Exp $

Add missing header for strncmp().

--- dltest/dltest.c.orig	2025-11-03 08:55:31.142567834 +0000
+++ dltest/dltest.c
@@ -28,6 +28,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 
 #ifdef WIN32
     #include <windows.h>
