$NetBSD$

Add missing header.
https://bugzilla.samba.org/show_bug.cgi?id=15932

--- source3/auth/user_util.c.orig	2024-07-29 09:03:15.302630200 +0000
+++ source3/auth/user_util.c
@@ -25,6 +25,10 @@
 #include "auth.h"
 #include "lib/gencache.h"
 
+#ifdef HAVE_NETGROUP_H
+#include <netgroup.h>
+#endif
+
 /*******************************************************************
  Map a username from a dos name to a unix name by looking in the username
  map. Note that this modifies the name in place.
