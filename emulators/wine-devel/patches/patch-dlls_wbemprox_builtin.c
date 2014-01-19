$NetBSD: patch-dlls_wbemprox_builtin.c,v 1.1 2014/01/19 10:58:23 adam Exp $

Reorder includes to fix 'select' being redefined error on NetBSD.

--- dlls/wbemprox/builtin.c.orig	2014-01-03 19:00:47.000000000 +0000
+++ dlls/wbemprox/builtin.c
@@ -25,12 +25,12 @@
 
 #include "ntstatus.h"
 #define WIN32_NO_STATUS
+#include "winsock2.h"
 #include "windef.h"
 #include "winbase.h"
 #include "initguid.h"
 #include "wbemcli.h"
 #include "wbemprov.h"
-#include "winsock2.h"
 #include "iphlpapi.h"
 #include "tlhelp32.h"
 #include "d3d10.h"
