$NetBSD: patch-src_modules_m__vhost.c,v 1.1 2015/11/07 22:46:25 dholland Exp $

Avoid unnecessary use of legacy sys/timeb.h, which doesn't exist on OpenBSD.

--- src/modules/m_vhost.c~	2014-07-26 15:42:10.000000000 +0000
+++ src/modules/m_vhost.c
@@ -32,8 +32,8 @@
 #include <string.h>
 #ifdef _WIN32
 #include <io.h>
-#endif
 #include <sys/timeb.h>
+#endif
 #include <fcntl.h>
 #include "h.h"
 #include "proto.h"
