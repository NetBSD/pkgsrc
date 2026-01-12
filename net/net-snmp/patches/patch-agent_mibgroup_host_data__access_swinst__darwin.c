$NetBSD: patch-agent_mibgroup_host_data__access_swinst__darwin.c,v 1.1 2026/01/12 13:05:57 tnn Exp $

mibgroup/host/data_access/swinst_darwin.c:378:17:
error: mixing declarations and code is incompatible with standards before C99 [-Werror,-Wdeclaration-after-statement]

--- agent/mibgroup/host/data_access/swinst_darwin.c.orig	2026-01-12 12:56:36.351557117 +0000
+++ agent/mibgroup/host/data_access/swinst_darwin.c
@@ -359,6 +359,7 @@ _check_classic_app(CFURLRef currentURL,
      */
     FSRef theFSRef;
     int theResFile;
+    VersRecHndl versHandle;
 
     if ((NULL == prodName) || (NULL == version))
        return -1;
@@ -375,7 +376,7 @@ _check_classic_app(CFURLRef currentURL,
         SNMP_CFRelease(*prodName);
         return -1;
     }
-    VersRecHndl versHandle = (VersRecHndl)Get1IndResource('vers', 1);
+    versHandle = (VersRecHndl)Get1IndResource('vers', 1);
     if (versHandle != NULL) {
         *version = CFStringCreateWithPascalString(kCFAllocatorDefault,
                        (**versHandle).shortVersion, kCFStringEncodingMacRoman);
