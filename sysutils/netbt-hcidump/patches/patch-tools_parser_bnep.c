$NetBSD: patch-tools_parser_bnep.c,v 1.1 2014/12/30 08:39:13 plunky Exp $

BSD vs Linux difference

--- tools/parser/bnep.c.orig	2012-12-24 17:46:55.000000000 +0000
+++ tools/parser/bnep.c
@@ -32,7 +32,7 @@
 #include <stdlib.h>
 #include <string.h>
 
-#include <net/ethernet.h>
+#include <net/ethertypes.h>
 
 #include "parser.h"
 
