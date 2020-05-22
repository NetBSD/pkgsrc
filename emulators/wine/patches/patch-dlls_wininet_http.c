$NetBSD: patch-dlls_wininet_http.c,v 1.1 2020/05/22 17:44:42 nia Exp $

Fix headers

--- dlls/wininet/http.c.orig	2019-03-15 20:18:31.000000000 +0000
+++ dlls/wininet/http.c
@@ -35,14 +35,14 @@
 #  include <zlib.h>
 #endif
 
-#include "winsock2.h"
-#include "ws2ipdef.h"
-
 #include <stdarg.h>
 #include <stdio.h>
 #include <time.h>
 #include <assert.h>
 
+#include "winsock2.h"
+#include "ws2ipdef.h"
+
 #include "windef.h"
 #include "winbase.h"
 #include "wininet.h"
