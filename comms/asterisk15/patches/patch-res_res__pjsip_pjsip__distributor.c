$NetBSD: patch-res_res__pjsip_pjsip__distributor.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip/pjsip_distributor.c.orig	2018-06-20 15:08:07.655594906 +0000
+++ res/res_pjsip/pjsip_distributor.c
@@ -18,13 +18,14 @@
 
 #include "asterisk.h"
 
+#include "asterisk/acl.h"
+#include "asterisk/taskprocessor.h"
+#include "asterisk/threadpool.h"
+
 #include <pjsip.h>
 
 #include "asterisk/res_pjsip.h"
-#include "asterisk/acl.h"
 #include "include/res_pjsip_private.h"
-#include "asterisk/taskprocessor.h"
-#include "asterisk/threadpool.h"
 #include "asterisk/res_pjsip_cli.h"
 
 static int distribute(void *data);
