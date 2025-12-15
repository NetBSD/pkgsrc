$NetBSD: patch-strallocnp.c,v 1.1 2025/12/15 21:29:34 wiz Exp $

Add missing header for strlen().

--- strallocnp.c.orig	2025-12-15 21:26:40.593244581 +0000
+++ strallocnp.c
@@ -4,6 +4,7 @@
 */
 
 # include	<stdio.h>
+# include	<string.h>
 
 # include	"memmgr.internal.h"
 # include	"memmgr.h"
