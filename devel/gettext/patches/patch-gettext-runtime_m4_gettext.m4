$NetBSD: patch-gettext-runtime_m4_gettext.m4,v 1.1 2018/12/27 15:09:53 joerg Exp $

--- gettext-runtime/m4/gettext.m4.orig	2018-12-26 00:43:05.863552486 +0000
+++ gettext-runtime/m4/gettext.m4
@@ -204,8 +204,7 @@ extern
 #ifdef __cplusplus
 "C"
 #endif
-const char *_nl_expand_alias (const char *);
-#define __GNU_GETTEXT_SYMBOL_EXPRESSION (_nl_msg_cat_cntr + *_nl_expand_alias (""))
+#define __GNU_GETTEXT_SYMBOL_EXPRESSION (_nl_msg_cat_cntr)
 #else
 #define __GNU_GETTEXT_SYMBOL_EXPRESSION 0
 #endif
@@ -230,8 +229,7 @@ extern
 #ifdef __cplusplus
 "C"
 #endif
-const char *_nl_expand_alias (const char *);
-#define __GNU_GETTEXT_SYMBOL_EXPRESSION (_nl_msg_cat_cntr + *_nl_expand_alias (""))
+#define __GNU_GETTEXT_SYMBOL_EXPRESSION (_nl_msg_cat_cntr)
 #else
 #define __GNU_GETTEXT_SYMBOL_EXPRESSION 0
 #endif
