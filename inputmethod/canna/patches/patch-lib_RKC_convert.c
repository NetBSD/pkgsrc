$NetBSD: patch-lib_RKC_convert.c,v 1.2 2026/06/30 14:17:52 tsutsui Exp $

Tweak include path to build without configure in unnecessary dirs

--- lib/RKC/convert.c.orig	2004-04-26 21:48:37.000000000 +0000
+++ lib/RKC/convert.c
@@ -27,7 +27,7 @@
 #include "rkcw.h"
 #include "canna/RK.h"
 #include "rkc.h"
-#include "IRproto.h"
+#include "../server/IRproto.h"
 #include "RKindep/file.h"
 
 #include <sys/types.h>
