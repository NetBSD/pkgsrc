$NetBSD: patch-extras_immodules_common_scim-bridge-string.c,v 1.1 2012/09/22 08:27:29 obache Exp $

* alloca.h is required for alloca(3C) on Solaris.

--- extras/immodules/common/scim-bridge-string.c.orig	2012-06-13 15:22:28.000000000 +0000
+++ extras/immodules/common/scim-bridge-string.c
@@ -24,6 +24,9 @@
 #include <stdlib.h>
 #include <string.h>
 #include <wchar.h>
+#ifdef __sun
+#include <alloca.h>
+#endif
 
 #include "scim-bridge-string.h"
 #include "scim-bridge-output.h"
