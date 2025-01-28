$NetBSD: patch-lib_Text_Markdown_Discount.xs,v 1.1 2025/01/28 00:47:04 schmonz Exp $

Don't expect to find this in /usr/include or equivalent.

--- lib/Text/Markdown/Discount.xs.orig	2025-01-27 22:57:34.104267097 +0000
+++ lib/Text/Markdown/Discount.xs
@@ -5,7 +5,7 @@
 #include "ppport.h"
 
 #include <string.h>
-#include <mkdio.h>
+#include "mkdio.h"
 
 MODULE = Text::Markdown::Discount		PACKAGE = Text::Markdown::Discount	PREFIX = TextMarkdown_
 
