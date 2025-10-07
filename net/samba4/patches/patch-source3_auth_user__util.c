$NetBSD$

--- source3/auth/user_util.c.orig	2025-10-07 19:00:41.861180195 +0000
+++ source3/auth/user_util.c
@@ -25,6 +25,8 @@
 #include "auth.h"
 #include "lib/gencache.h"
 
+#include <netgroup.h>
+
 /*******************************************************************
  Map a username from a dos name to a unix name by looking in the username
  map. Note that this modifies the name in place.
