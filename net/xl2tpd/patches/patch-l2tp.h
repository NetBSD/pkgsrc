$NetBSD: patch-l2tp.h,v 1.2 2013/07/12 19:06:31 christos Exp $

Include common.h first since it typedefs things other headers need
Conditionalize in_pktinfo

--- l2tp.h.orig	2013-06-17 06:17:24.000000000 -0400
+++ l2tp.h	2013-07-12 15:00:53.000000000 -0400
@@ -28,13 +28,13 @@
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
@@ -172,7 +172,9 @@
     struct call *self;
     struct lns *lns;            /* LNS that owns us */
     struct lac *lac;            /* LAC that owns us */
+#ifdef IP_PKTINFO
     struct in_pktinfo my_addr;  /* Address of my endpoint */
+#endif
 };
 
 struct tunnel_list
