$NetBSD: patch-mysys_my__symlink.c,v 1.1 2017/07/20 16:41:10 adam Exp $

Add missing include, so MY_STAT gets defined.

--- mysys/my_symlink.c.orig	2017-07-19 17:59:04.500183903 +0000
+++ mysys/my_symlink.c
@@ -15,6 +15,7 @@
 
 #include "mysys_priv.h"
 #include "my_sys.h"
+#include "my_dir.h"
 #include "mysys_err.h"
 #include <m_string.h>
 #include <errno.h>
