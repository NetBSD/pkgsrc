$NetBSD: patch-exp-gfx.c,v 1.1 2011/09/25 19:52:30 joerg Exp $

--- exp-gfx.c.orig	2011-09-25 09:10:07.000000000 +0000
+++ exp-gfx.c
@@ -3,6 +3,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <zlib.h>
 
 #include "lang.h"
 #include "export.h"
