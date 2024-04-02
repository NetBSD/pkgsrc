$NetBSD: patch-common_message.c,v 1.3 2024/04/02 02:13:01 charlotte Exp $

On DragonFly, xlocale.h provides all the locale functionality (locale.h
provides only some of it).

--- common/message.c.orig	2024-04-01 18:58:42.168426000 -0700
+++ common/message.c	2024-04-01 18:59:19.339981000 -0700
@@ -51,7 +51,11 @@
 #include <assert.h>
 #include <errno.h>
 #ifdef HAVE_LOCALE_H
+#ifdef __DragonFly__
+#include <xlocale.h>
+#else
 #include <locale.h>
+#endif // __DragonFly__
 #endif
 #include <stdarg.h>
 #include <stdlib.h>
