$NetBSD: patch-include_ipmitool_ipmi__delloem.h,v 1.1 2026/10/28 16:38:09 jperkin Exp $

Fix for https://github.com/ipmitool/ipmitool/issues/332 from
https://codeberg.org/IPMITool/ipmitool/commit/206dba615d740a31e881861c86bcc8daafd9d5b1.patch

--- include/ipmitool/ipmi_delloem.h.orig	2022-09-01 18:42:31.000000000 +0000
+++ include/ipmitool/ipmi_delloem.h
@@ -343,10 +343,6 @@ typedef struct _power_headroom
     uint16_t peakheadroom;
 } __attribute__ ((packed)) POWER_HEADROOM;
 
-struct vFlashstr {
-	uint8_t val;
-	const char * str;
-};
 typedef struct ipmi_vFlash_extended_info
 {
 	uint8_t  vflashcompcode;
