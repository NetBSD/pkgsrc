$NetBSD: patch-lasso-id-ff-provider.c,v 1.1 2011/09/08 00:17:03 joerg Exp $

--- lasso/id-ff/provider.c.orig	2011-09-07 03:26:19.000000000 +0000
+++ lasso/id-ff/provider.c
@@ -64,6 +64,7 @@ use this default role to access descript
 
 #include "../saml-2.0/providerprivate.h"
 #include <unistd.h>
+#include <string.h>
 #include "../utils.h"
 #include "../debug.h"
 
