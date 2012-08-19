$NetBSD: patch-extras_immodules_client-common_scim-bridge-client-output.c,v 1.1 2012/08/19 08:09:08 obache Exp $

--- extras/immodules/client-common/scim-bridge-client-output.c.orig	2012-06-13 15:22:28.000000000 +0000
+++ extras/immodules/client-common/scim-bridge-client-output.c
@@ -20,6 +20,7 @@
 #include <stdarg.h>
 #include <stdio.h>
 #include <string.h>
+#include <stdlib.h>
 
 #include "scim-bridge-debug.h"
 #include "scim-bridge-output.h"
