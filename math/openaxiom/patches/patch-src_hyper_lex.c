$NetBSD: patch-src_hyper_lex.c,v 1.1 2012/03/23 21:21:36 asau Exp $

--- src/hyper/lex.c.orig	2011-07-07 19:04:11.000000000 +0000
+++ src/hyper/lex.c
@@ -62,6 +62,7 @@
 #include <ctype.h>
 #include <setjmp.h>
 #include <stdlib.h>
+#include <string.h>
 
 #include "debug.h"
 #include "sockio.h"
