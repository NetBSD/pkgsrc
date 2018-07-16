$NetBSD: patch-res_res__pjsip__sips__contact.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_sips_contact.c.orig	2018-06-20 15:18:05.179232502 +0000
+++ res/res_pjsip_sips_contact.c
@@ -24,10 +24,11 @@
 
 #include "asterisk.h"
 
+#include "asterisk/module.h"
+
 #include <pjsip.h>
 
 #include "asterisk/res_pjsip.h"
-#include "asterisk/module.h"
 
 /*!
  * \brief Upgrade Contact URIs on outgoing SIP requests to SIPS if required.
