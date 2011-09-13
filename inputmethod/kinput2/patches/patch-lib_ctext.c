$NetBSD: patch-lib_ctext.c,v 1.1 2011/09/13 07:28:48 mef Exp $

To compile with ja-freewnn-lib-1.11alpah22

--- lib/ctext.c.orig	2002-10-03 09:35:28.000000000 +0000
+++ lib/ctext.c
@@ -72,4 +72,6 @@ static char *rcsid = "$Id: ctext.c,v 2.6
 #endif
 
+#include <string.h>
+
 typedef unsigned short	wchar;
 
