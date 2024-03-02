$NetBSD: patch-lib_nicInfo_nicInfoPosix.c,v 1.3 2024/03/02 13:52:42 wiz Exp $

On NetBSD, res_ndestroy() corresponds to res_ninit().
PR 57983

--- lib/nicInfo/nicInfoPosix.c.orig	2022-11-03 13:51:05.000000000 +0000
+++ lib/nicInfo/nicInfoPosix.c
@@ -898,14 +898,22 @@ RecordResolverInfo(NicInfoV3 *nicInfo)  
     */
    nicInfo->dnsConfigInfo = dnsConfigInfo;
 
+#if defined(__NetBSD__)
+   res_ndestroy(&res);
+#else
    res_nclose(&res);
+#endif
 
    return TRUE;
 
 fail:
    VMX_XDR_FREE(xdr_DnsConfigInfo, dnsConfigInfo);
    free(dnsConfigInfo);
+#if defined(__NetBSD__)
+   res_ndestroy(&res);
+#else
    res_nclose(&res);
+#endif
 
    return FALSE;
 }
