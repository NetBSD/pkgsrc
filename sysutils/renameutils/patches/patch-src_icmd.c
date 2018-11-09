$NetBSD: patch-src_icmd.c,v 1.1 2018/11/09 12:50:49 bsiegert Exp $

Use mv and cp from GNU coreutils.
--- src/icmd.c.orig	2008-09-21 09:10:29 UTC
+++ src/icmd.c
@@ -45,8 +45,8 @@
 #include "common/string-utils.h"
 #include "common/common.h"
 
-#define MV_COMMAND "mv"
-#define CP_COMMAND "cp"
+#define MV_COMMAND "gmv"
+#define CP_COMMAND "gcp"
 /* This list should be up to date with mv and cp!
  * It was last updated on 2007-11-30 for
  * Debian coreutils 5.97-5.4 in unstable.
