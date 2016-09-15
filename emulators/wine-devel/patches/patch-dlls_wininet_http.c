$NetBSD: patch-dlls_wininet_http.c,v 1.1 2016/09/15 09:25:53 maya Exp $

--- dlls/wininet/http.c.orig	2016-09-02 16:39:28.000000000 +0000
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
