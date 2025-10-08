$NetBSD: patch-lib_util_access.c,v 1.2 2025/10/08 14:28:53 wiz Exp $

Add missing header.
https://bugzilla.samba.org/show_bug.cgi?id=15932

--- lib/util/access.c.orig	2025-10-07 19:00:15.593339882 +0000
+++ lib/util/access.c
@@ -23,6 +23,8 @@
 #include "lib/util/unix_match.h"
 #include "lib/util/smb_strtox.h"
 
+#include <netgroup.h>
+
 #define NAME_INDEX 0
 #define ADDR_INDEX 1
 
