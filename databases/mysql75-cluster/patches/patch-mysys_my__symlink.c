$NetBSD: patch-mysys_my__symlink.c,v 1.1 2022/04/17 04:07:14 jnemeth Exp $

--- mysys/my_symlink.c.orig	2021-09-14 09:08:08.000000000 +0000
+++ mysys/my_symlink.c
@@ -27,6 +27,7 @@
 
 #include "mysys_priv.h"
 #include "my_sys.h"
+#include "my_dir.h"
 #include "mysys_err.h"
 #include <m_string.h>
 #include <errno.h>
