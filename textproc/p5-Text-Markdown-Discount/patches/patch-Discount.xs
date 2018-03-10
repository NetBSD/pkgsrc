$NetBSD: patch-Discount.xs,v 1.1 2018/03/10 05:45:02 schmonz Exp $

Don't expect to find this in /usr/include or equivalent.

--- Discount.xs.orig	2013-08-09 20:07:01.000000000 +0000
+++ Discount.xs
@@ -5,7 +5,7 @@
 #include "ppport.h"
 
 #include <string.h>
-#include <mkdio.h>
+#include "mkdio.h"
 
 MODULE = Text::Markdown::Discount		PACKAGE = Text::Markdown::Discount	PREFIX = TextMarkdown_
 
