$NetBSD: patch-level.c,v 1.1 2025/09/29 20:41:50 mrg Exp $

Add missing header for abs(3).

--- level.c.orig	1999-06-22 07:40:33.000000000 -0700
+++ level.c	2025-09-25 10:55:29.767806334 -0700
@@ -27,6 +27,7 @@
  */
 
 #include <curses.h>
+#include <stdlib.h>
 
 #include "zombies.h"
 
