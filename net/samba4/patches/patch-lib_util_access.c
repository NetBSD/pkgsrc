$NetBSD: patch-lib_util_access.c,v 1.3.2.2 2025/10/23 03:25:09 maya Exp $

Add missing header.
https://bugzilla.samba.org/show_bug.cgi?id=15932

--- lib/util/access.c.orig	2024-07-29 09:03:15.058628300 +0000
+++ lib/util/access.c
@@ -23,6 +23,10 @@
 #include "lib/util/unix_match.h"
 #include "lib/util/smb_strtox.h"
 
+#ifdef HAVE_NETGROUP_H
+#include <netgroup.h>
+#endif
+
 #define NAME_INDEX 0
 #define ADDR_INDEX 1
 
