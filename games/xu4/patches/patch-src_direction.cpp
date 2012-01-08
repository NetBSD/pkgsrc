$NetBSD: patch-src_direction.cpp,v 1.1.1.1 2012/01/08 15:52:12 wiz Exp $

Add missing header.

--- src/direction.cpp.orig	2004-05-22 21:03:25.000000000 +0000
+++ src/direction.cpp
@@ -9,6 +9,7 @@
 #include "debug.h"
 #include "event.h"
 #include "utils.h"
+#include <stdlib.h>
 
 /**
  * Returns the opposite direction.
