$NetBSD: patch-appUtil_csvsheet.c,v 1.1 2014/03/25 23:13:21 asau Exp $

--- appUtil/csvsheet.c.orig	2009-10-16 15:20:58.000000000 +0000
+++ appUtil/csvsheet.c
@@ -1,7 +1,6 @@
 #   include	<stdio.h>
 #   include	<string.h>
 #   include	<stdlib.h>
-#   include	<malloc.h>
 #   include	<time.h>
 
 #   include	"csv.h"
