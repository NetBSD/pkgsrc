$NetBSD: patch-textio_textio.h,v 1.2 2013/03/07 22:05:13 joerg Exp $

--- textio/textio.h.orig	2013-03-02 22:26:17.000000000 +0000
+++ textio/textio.h
@@ -25,6 +25,7 @@
 #ifndef _TEXTIO_H
 #define _TEXTIO_H
 
+#include <stdarg.h>
 #include "utils/magic.h"
 
 #ifdef MAGIC_WRAPPER
@@ -65,6 +66,7 @@ extern void TxUseMore();
 extern void TxStopMore();
 
 /* printing procedures with variable arguments lists */
+extern void VTxError(char *, va_list);
 extern void TxError(char *, ...);
 extern void TxPrintf(char *, ...);
 extern char *TxPrintString(char *, ...);
