$NetBSD: patch-actions.cc,v 1.1 2011/11/25 21:53:26 joerg Exp $

--- actions.cc.orig	2011-11-25 18:01:36.000000000 +0000
+++ actions.cc
@@ -21,6 +21,8 @@
 #ifdef HAVE_CONFIG_H
 #  include <config.h>
 #endif
+#include <cstring>
+#include <cstdlib>
 
 #include "gamewin.h"
 #include "actions.h"
