$NetBSD: patch-mpconfigport.h,v 1.1 2016/01/18 07:54:51 agc Exp $

Generalise for all BSDs

--- mpconfigport.h	2016/01/09 20:30:55	1.1
+++ mpconfigport.h	2016/01/09 20:32:14
@@ -251,7 +251,8 @@
 // We need to provide a declaration/definition of alloca()
 // unless support for it is disabled.
 #if !defined(MICROPY_NO_ALLOCA) || MICROPY_NO_ALLOCA == 0
-#ifdef __FreeBSD__
+#include <sys/param.h>
+#if (defined(BSD) && BSD >= 199506)
 #include <stdlib.h>
 #else
 #include <alloca.h>
