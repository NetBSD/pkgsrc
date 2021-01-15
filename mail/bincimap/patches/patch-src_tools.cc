$NetBSD: patch-src_tools.cc,v 1.1 2021/01/15 22:01:29 schmonz Exp $

Fix "error: 'strdup' was not declared in this scope" on at least NetBSD
and Tribblix.

Fix "error: '::getenv' has not been declared" on at least CentOS 7.

--- src/tools.cc.orig	2005-01-08 10:20:48.000000000 +0000
+++ src/tools.cc
@@ -35,6 +35,8 @@
 #include <config.h>
 #endif
 #include <errno.h>
+#include <stdlib.h>
+#include <string.h>
 
 #include "tools.h"
 
