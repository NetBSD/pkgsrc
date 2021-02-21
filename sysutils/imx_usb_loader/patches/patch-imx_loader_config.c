$NetBSD: patch-imx_loader_config.c,v 1.1 2021/02/21 12:33:32 martin Exp $

PATH_MAX is used, so include limits.h

--- imx_loader_config.c.orig	2020-05-17 05:45:34.000000000 +0200
+++ imx_loader_config.c	2021-02-20 17:52:52.815546397 +0100
@@ -21,6 +21,7 @@
 #include <string.h>
 #include <stdlib.h>
 #include <stdint.h>
+#include <limits.h>
 
 #include "portable.h"
 #include "imx_sdp.h"
