$NetBSD: patch-memmgr.internal.h,v 1.1 2025/12/15 21:29:34 wiz Exp $

Remove broken strcpy() prototype.

--- memmgr.internal.h.orig	2025-12-15 21:27:18.993899488 +0000
+++ memmgr.internal.h
@@ -2,7 +2,6 @@
 
 #define _MEMMGR_INTERNAL_H
 
-extern char	*strcpy ();
 
 # if defined(__STDC__) || defined(THINK_C)
 # include	<stdlib.h>
