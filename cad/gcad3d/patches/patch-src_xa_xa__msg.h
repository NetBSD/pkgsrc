$NetBSD: patch-src_xa_xa__msg.h,v 1.1 2022/05/23 19:10:03 plunky Exp $

include <stdarg.h> for va_list

--- src/xa/xa_msg.h.orig	2020-11-16 07:09:05.000000000 +0000
+++ src/xa/xa_msg.h
@@ -1,6 +1,6 @@
+#include <stdarg.h>                    // va_list
 /* Messages.
 needs
-#include <stdarg.h>                    // va_list
 
 #include "../xa/xa_msg.h"              // MSG_*
 
