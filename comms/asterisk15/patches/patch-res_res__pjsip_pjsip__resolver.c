$NetBSD: patch-res_res__pjsip_pjsip__resolver.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip/pjsip_resolver.c.orig	2018-06-20 15:09:57.824142836 +0000
+++ res/res_pjsip/pjsip_resolver.c
@@ -18,9 +18,6 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-#include <pjlib-util/errno.h>
-
 #include <arpa/nameser.h>
 
 #include "asterisk/astobj2.h"
@@ -28,11 +25,16 @@
 #include "asterisk/dns_query_set.h"
 #include "asterisk/dns_srv.h"
 #include "asterisk/dns_naptr.h"
-#include "asterisk/res_pjsip.h"
-#include "include/res_pjsip_private.h"
+#include "asterisk/network.h"
 #include "asterisk/taskprocessor.h"
 #include "asterisk/threadpool.h"
 
+#include <pjsip.h>
+#include <pjlib-util/errno.h>
+
+#include "asterisk/res_pjsip.h"
+#include "include/res_pjsip_private.h"
+
 #ifdef HAVE_PJSIP_EXTERNAL_RESOLVER
 
 /*! \brief Structure which contains transport+port information for an active query */
