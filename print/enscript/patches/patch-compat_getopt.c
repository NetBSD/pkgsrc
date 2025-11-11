$NetBSD: patch-compat_getopt.c,v 1.1 2025/11/11 22:25:52 wiz Exp $

Add missing header for strlen().

--- compat/getopt.c.orig	2025-11-11 22:24:39.161133855 +0000
+++ compat/getopt.c
@@ -43,6 +43,7 @@
 #endif
 
 #include <stdio.h>
+#include <string.h>
 
 /* Comment out all this code if we are using the GNU C Library, and are not
    actually compiling the library itself.  This code is part of the GNU C
