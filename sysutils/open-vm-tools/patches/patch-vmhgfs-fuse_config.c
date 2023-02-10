$NetBSD: patch-vmhgfs-fuse_config.c,v 1.4 2023/02/10 01:22:08 khorben Exp $

* The original SysCompatCheck() only works on Linux.
* librefuse didn't support the old style -ho option. Fixed in HEAD.

--- vmhgfs-fuse/config.c.orig	2022-02-11 15:32:22.000000000 +0000
+++ vmhgfs-fuse/config.c
@@ -24,6 +24,7 @@
 #include "module.h"
 #include <fuse_lowlevel.h>
 #include <sys/utsname.h>
+#include <sys/stat.h>
 
 #ifdef VMX86_DEVEL
 int LOGLEVEL_THRESHOLD = 4;
