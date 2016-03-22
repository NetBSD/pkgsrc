$NetBSD: patch-unix_mpconfigport.h,v 1.1 2016/03/22 19:01:17 joerg Exp $

Generalise for all BSDs

--- unix/mpconfigport.h.orig	2015-12-31 14:43:19.000000000 +0000
+++ unix/mpconfigport.h
@@ -261,7 +261,8 @@ void mp_hal_dupterm_tx_strn(const char *
 // We need to provide a declaration/definition of alloca()
 // unless support for it is disabled.
 #if !defined(MICROPY_NO_ALLOCA) || MICROPY_NO_ALLOCA == 0
-#ifdef __FreeBSD__
+#include <sys/param.h>
+#if (defined(BSD) && BSD >= 199506)
 #include <stdlib.h>
 #else
 #include <alloca.h>
