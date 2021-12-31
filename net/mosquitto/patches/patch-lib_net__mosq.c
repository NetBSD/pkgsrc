$NetBSD: patch-lib_net__mosq.c,v 1.3 2021/12/31 16:02:09 triaxx Exp $

Work around lack of strnlen on older NetBSD.

Not sent upstream becaus POSIX requires strnlen.

--- lib/net_mosq.c.orig	2021-11-17 00:28:35.000000000 +0000
+++ lib/net_mosq.c
@@ -77,6 +77,13 @@ Contributors:
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
