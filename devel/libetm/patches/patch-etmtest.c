$NetBSD: patch-etmtest.c,v 1.1 2025/12/11 21:28:58 vins Exp $

Add missing includes.

--- etmtest.c.orig	1996-05-19 01:05:35.000000000 +0000
+++ etmtest.c
@@ -15,6 +15,8 @@
 # endif
 
 # include	<stdio.h>
+# include	<stdlib.h>
+# include	<string.h>
 
 # include	"etm.h"
 
