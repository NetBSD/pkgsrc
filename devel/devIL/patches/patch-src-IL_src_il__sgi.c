$NetBSD: patch-src-IL_src_il__sgi.c,v 1.1 2022/09/24 21:06:42 he Exp $

Use <altivec.h> if __ALTIVEC__ is defined.

--- src-IL/src/il_sgi.c.orig	2009-03-08 07:10:09.000000000 +0000
+++ src-IL/src/il_sgi.c
@@ -16,6 +16,10 @@
 #include "il_manip.h"
 #include <limits.h>
 
+#ifdef __ALTIVEC__
+#include <altivec.h>
+#endif
+
 static char *FName = NULL;
 
 /*----------------------------------------------------------------------------*/
