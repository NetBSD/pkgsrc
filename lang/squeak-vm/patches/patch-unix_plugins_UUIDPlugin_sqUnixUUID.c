$NetBSD: patch-unix_plugins_UUIDPlugin_sqUnixUUID.c,v 1.1 2015/03/15 00:41:34 taca Exp $

Do not include <sys/uuid.h> and other uuid.h.

--- unix/plugins/UUIDPlugin/sqUnixUUID.c.orig	2012-09-13 19:25:58.000000000 +0000
+++ unix/plugins/UUIDPlugin/sqUnixUUID.c
@@ -3,7 +3,8 @@
 #if defined(HAVE_SYS_UUID_H)
 # include <sys/types.h>
 # include <sys/uuid.h>
-#endif
+
+#else
 
 #if defined(HAVE_UUID_UUID_H)
 # include <uuid/uuid.h>
@@ -11,6 +12,8 @@
 # include <uuid.h>
 #endif
 
+#endif
+
 #include "sq.h"
 
 
