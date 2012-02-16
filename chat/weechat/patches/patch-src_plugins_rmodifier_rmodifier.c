$NetBSD: patch-src_plugins_rmodifier_rmodifier.c,v 1.1 2012/02/16 16:11:25 hans Exp $

Include strings.h for rindex().

--- src/plugins/rmodifier/rmodifier.c.orig	2011-01-01 15:45:45.000000000 +0100
+++ src/plugins/rmodifier/rmodifier.c	2012-01-24 19:49:44.272350994 +0100
@@ -25,6 +25,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
+#include <strings.h>
 
 #include "../weechat-plugin.h"
 #include "rmodifier.h"
