$NetBSD: patch-lib_RKC_convert.c,v 1.1 2015/10/18 03:58:31 tsutsui Exp $

Tweak include path to build without configure in unnecessary dirs

--- lib/RKC/convert.c.orig	2004-04-26 21:48:37.000000000 +0000
+++ lib/RKC/convert.c
@@ -30,7 +30,7 @@ static char rcs_id[] = "$Id: convert.c,v
 #include "rkcw.h"
 #include "canna/RK.h"
 #include "rkc.h"
-#include "IRproto.h"
+#include "../server/IRproto.h"
 #include "RKindep/file.h"
 
 #include <sys/types.h>
