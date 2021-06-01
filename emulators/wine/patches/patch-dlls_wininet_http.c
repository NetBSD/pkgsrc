$NetBSD: patch-dlls_wininet_http.c,v 1.2 2021/06/01 05:05:54 adam Exp $

Fix headers

--- dlls/wininet/http.c.orig	2020-06-02 13:09:41.000000000 +0000
+++ dlls/wininet/http.c
@@ -29,9 +29,6 @@
 
 #include <stdlib.h>
 
-#include "winsock2.h"
-#include "ws2ipdef.h"
-
 #include <stdarg.h>
 #include <stdio.h>
 #include <time.h>
@@ -39,6 +36,9 @@
 #include <errno.h>
 #include <limits.h>
 
+#include "winsock2.h"
+#include "ws2ipdef.h"
+
 #include "windef.h"
 #include "winbase.h"
 #include "wininet.h"
