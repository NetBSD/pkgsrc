$NetBSD: patch-l2tp.h,v 1.3 2017/10/13 17:24:05 christos Exp $

Include common.h first since it typedefs things other headers need

--- l2tp.h.orig	2017-08-02 13:46:06.000000000 -0400
+++ l2tp.h	2017-10-13 12:46:33.946695069 -0400
@@ -30,13 +30,13 @@
 #endif
 #include "osport.h"
 #include "scheduler.h"
+#include "common.h"
 #include "misc.h"
 #include "file.h"
 #include "call.h"
 #include "avp.h"
 #include "control.h"
 #include "aaa.h"
-#include "common.h"
 #include "ipsecmast.h"
 
 #define CONTROL_PIPE "/var/run/xl2tpd/l2tp-control"
