$NetBSD: patch-res_res__pjsip__phoneprov__provider.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_phoneprov_provider.c.orig	2018-06-20 15:28:01.690262506 +0000
+++ res/res_pjsip_phoneprov_provider.c
@@ -41,12 +41,13 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-
-#include "asterisk/res_pjsip.h"
 #include "asterisk/module.h"
 #include "asterisk/sorcery.h"
 #include "asterisk/phoneprov.h"
+
+#include <pjsip.h>
+
+#include "asterisk/res_pjsip.h"
 #include "res_pjsip/include/res_pjsip_private.h"
 
 /*** DOCUMENTATION
