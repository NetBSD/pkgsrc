$NetBSD: patch-tstest.c,v 1.1 2025/12/11 20:57:34 vins Exp $

Add missing includes.

--- tstest.c.orig	2025-12-11 20:46:35.127892267 +0000
+++ tstest.c
@@ -9,6 +9,8 @@
 */
 
 # include	<stdio.h>
+# include	<stdlib.h>
+# include	<string.h>
 
 # include	"tokenscan.h"
 
