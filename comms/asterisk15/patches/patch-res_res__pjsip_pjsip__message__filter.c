$NetBSD: patch-res_res__pjsip_pjsip__message__filter.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip/pjsip_message_filter.c.orig	2018-06-20 15:11:13.041603718 +0000
+++ res/res_pjsip/pjsip_message_filter.c
@@ -18,6 +18,8 @@
 
 #include "asterisk.h"
 
+#include "asterisk/network.h"
+
 #include <pjsip.h>
 #include <pjsip_ua.h>
 
