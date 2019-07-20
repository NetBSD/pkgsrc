$NetBSD: patch-lib_net__mosq.c,v 1.1 2019/07/20 23:09:27 gdt Exp $

Work around lack of strnlen on older NetBSD.

Not sent upstream becaus POSIX requires strnlen.

--- lib/net_mosq.c.orig	2019-04-26 16:07:59.000000000 +0000
+++ lib/net_mosq.c
@@ -69,6 +69,13 @@ Contributors:
 #include "time_mosq.h"
 #include "util_mosq.h"
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if ! __NetBSD_Prereq__(6,0,0)
+#define strnlen(s,l) strlen(s)
+#endif /* __NetBSD_Prereq__ */
+#endif /* __NetBSD__ */
+
 #ifdef WITH_TLS
 int tls_ex_index_mosq = -1;
 UI_METHOD *_ui_method = NULL;
