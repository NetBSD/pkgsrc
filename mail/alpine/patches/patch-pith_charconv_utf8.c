$NetBSD: patch-pith_charconv_utf8.c,v 1.1 2025/09/08 12:57:17 vins Exp $

Provide a declaration of wcwidth().

--- pith/charconv/utf8.c.orig	2025-09-08 11:34:06.467704256 +0000
+++ pith/charconv/utf8.c
@@ -12,6 +12,7 @@
  * ========================================================================
  */
 
+#include <wchar.h>
 
 /* includable WITHOUT dependency on c-client */
 #include "../../c-client/mail.h"
