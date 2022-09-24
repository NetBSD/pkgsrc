$NetBSD: patch-src-IL_src_il__quantizer.c,v 1.1 2022/09/24 21:06:42 he Exp $

Use <altivec.h> if __ALTIVEC__ is defined.

--- src-IL/src/il_quantizer.c.orig	2009-03-08 07:10:09.000000000 +0000
+++ src-IL/src/il_quantizer.c
@@ -35,6 +35,10 @@
 
 #include "il_internal.h"
 
+#ifdef __ALTIVEC__
+#include <altivec.h>
+#endif
+
 #define MAXCOLOR	256
 #define	RED			2
 #define	GREEN		1
