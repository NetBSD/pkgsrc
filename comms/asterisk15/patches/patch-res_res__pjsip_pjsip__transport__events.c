$NetBSD: patch-res_res__pjsip_pjsip__transport__events.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip/pjsip_transport_events.c.orig	2018-06-20 15:11:40.942746700 +0000
+++ res/res_pjsip/pjsip_transport_events.c
@@ -29,11 +29,13 @@
 
 #include "asterisk.h"
 
-#include "asterisk/res_pjsip.h"
-#include "include/res_pjsip_private.h"
 #include "asterisk/linkedlists.h"
+#include "asterisk/network.h"
 #include "asterisk/vector.h"
 
+#include "asterisk/res_pjsip.h"
+#include "include/res_pjsip_private.h"
+
 /* ------------------------------------------------------------------- */
 
 /*! \brief Number of buckets for monitored active transports */
