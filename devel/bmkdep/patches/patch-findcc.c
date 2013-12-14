$NetBSD: patch-findcc.c,v 1.3 2013/12/14 17:56:22 cheusov Exp $

--- findcc.c.orig	2013-10-09 14:38:38.000000000 +0000
+++ findcc.c
@@ -33,7 +33,6 @@
 #include "nbtool_config.h"
 #endif
 
-#include <sys/cdefs.h>
 #if !defined(lint)
 __COPYRIGHT("@(#) Copyright (c) 1999 The NetBSD Foundation, Inc.\
  All rights reserved.");
