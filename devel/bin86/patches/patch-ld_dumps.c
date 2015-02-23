$NetBSD: patch-ld_dumps.c,v 1.1 2015/02/23 18:20:21 joerg Exp $

--- ld/dumps.c.orig	2015-02-22 19:51:17.000000000 +0000
+++ ld/dumps.c
@@ -1,7 +1,7 @@
 /* dumps.c - print data about symbols and modules for linker */
 
 /* Copyright (C) 1994 Bruce Evans */
-
+#include <string.h>
 #include "const.h"
 #include "obj.h"
 #include "type.h"
