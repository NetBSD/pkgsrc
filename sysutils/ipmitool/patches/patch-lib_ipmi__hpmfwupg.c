$NetBSD: patch-lib_ipmi__hpmfwupg.c,v 1.1 2013/03/02 17:56:13 joerg Exp $

--- lib/ipmi_hpmfwupg.c.orig	2013-03-01 13:04:13.000000000 +0000
+++ lib/ipmi_hpmfwupg.c
@@ -1233,7 +1233,7 @@ int HpmfwupgTargetCheck(struct ipmi_intf
     if (rc != HPMFWUPG_SUCCESS)
     {
         lprintf(LOG_NOTICE,"Verify whether the Target board is present \n");
-        return;
+        return HPMFWUPG_ERROR;
     }
 
     rc = HpmfwupgGetTargetUpgCapabilities(intf, &targetCapCmd);
@@ -3516,7 +3516,7 @@ int ipmi_hpmfwupg_main(struct ipmi_intf 
    if ( (argc == 0) || (strcmp(argv[0], "help") == 0) ) 
    {
       HpmfwupgPrintUsage();
-      return;
+      return HPMFWUPG_ERROR;
     }
    if ( (strcmp(argv[0], "check") == 0) )
    {
