$NetBSD: patch-src_tools.c,v 1.1 2025/10/12 02:57:36 mrg Exp $

Include msg.h.

--- src/tools.c.orig	2003-01-29 14:26:09.000000000 -0800
+++ src/tools.c	2025-10-11 19:45:38.224930564 -0700
@@ -45,6 +45,7 @@
 
 #include "command.h"
 #include "vmg.h"
+#include "msg.h"
 
 /*
  * get functions: they return some data
