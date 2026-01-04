$NetBSD: patch-dict-web1913-1.4_libmaa_getopt.c,v 1.1 2026/01/04 14:08:24 wiz Exp $

Add missing header.

--- dict-web1913-1.4/libmaa/getopt.c.orig	1998-02-22 19:32:21.000000000 +0000
+++ dict-web1913-1.4/libmaa/getopt.c
@@ -43,6 +43,7 @@ Cambridge, MA 02139, USA.  */
 #endif
 
 #include <stdio.h>
+#include <string.h>
 
 #ifdef __sparc__
 extern int fprintf( FILE *, const char *, ... );
