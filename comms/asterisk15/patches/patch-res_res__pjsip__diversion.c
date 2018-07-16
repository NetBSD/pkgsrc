$NetBSD: patch-res_res__pjsip__diversion.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_diversion.c.orig	2018-06-11 21:21:37.000000000 +0000
+++ res/res_pjsip_diversion.c
@@ -25,15 +25,16 @@
 
 #include "asterisk.h"
 
+#include "asterisk/callerid.h"
+#include "asterisk/channel.h"
+#include "asterisk/module.h"
+#include "asterisk/strings.h"
+
 #include <pjsip.h>
 #include <pjsip_ua.h>
 
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_session.h"
-#include "asterisk/callerid.h"
-#include "asterisk/channel.h"
-#include "asterisk/module.h"
-#include "asterisk/strings.h"
 
 static const pj_str_t diversion_name = { "Diversion", 9 };
 
@@ -59,7 +60,7 @@ static int sip_is_token(const char *str)
 
 	is_token = 1;
 	do {
-		if (!isalnum(*str)
+		if (!isalnum((unsigned char)*str)
 			&& !strchr("-.!%*_+`'~", *str)) {
 			/* The character is not allowed in a token. */
 			is_token = 0;
