$NetBSD: patch-src_common_cidr.c,v 1.1 2013/10/31 02:25:17 minskim Exp $

--- src/common/cidr.c.orig	2010-04-05 00:58:01.000000000 +0000
+++ src/common/cidr.c
@@ -34,7 +34,9 @@
 #include "config.h"
 #include "defines.h"
 #include "common.h"
+#ifndef HAVE_STRLCPY
 #include "lib/strlcpy.h"
+#endif
 
 #include <stdio.h>
 #include <stdlib.h>
