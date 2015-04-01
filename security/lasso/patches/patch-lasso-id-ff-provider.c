$NetBSD: patch-lasso-id-ff-provider.c,v 1.2 2015/04/01 14:05:02 manu Exp $

--- lasso/id-ff/provider.c.orig	2014-07-30 17:16:07.000000000 +0200
+++ lasso/id-ff/provider.c	2015-03-25 11:29:15.000000000 +0100
@@ -62,8 +62,9 @@
 #include "providerprivate.h"
 
 #include "../saml-2.0/providerprivate.h"
 #include <unistd.h>
+#include <string.h>
 #include "../utils.h"
 #include "../debug.h"
 #include "../keyprivate.h"
 
