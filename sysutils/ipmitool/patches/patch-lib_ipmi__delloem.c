$NetBSD: patch-lib_ipmi__delloem.c,v 1.1 2026/10/28 16:38:09 jperkin Exp $

Fix for https://github.com/ipmitool/ipmitool/issues/332 from
https://codeberg.org/IPMITool/ipmitool/commit/206dba615d740a31e881861c86bcc8daafd9d5b1.patch

--- lib/ipmi_delloem.c.orig	2022-09-01 18:42:31.000000000 +0000
+++ lib/ipmi_delloem.c
@@ -115,7 +115,7 @@ char NIC_Selection_Mode_String_12g[] [50
 	"shared with failover all loms"
 };
 
-const struct vFlashstr vFlash_completion_code_vals[] = {
+const struct valstr vFlash_completion_code_vals[] = {
 	{0x00, "SUCCESS"},
 	{0x01, "NO_SD_CARD"},
 	{0x63, "UNKNOWN_ERROR"},
@@ -232,8 +232,6 @@ static void ipmi_powermonitor_usage(void
 /* vFlash Function prototypes */
 static int ipmi_delloem_vFlash_main(struct ipmi_intf *intf, int argc,
 		char **argv);
-const char *get_vFlash_compcode_str(uint8_t vflashcompcode,
-		const struct vFlashstr *vs);
 static int ipmi_get_sd_card_info(struct ipmi_intf *intf);
 static int ipmi_delloem_vFlash_process(struct ipmi_intf *intf, int current_arg,
 		char **argv);
@@ -3757,28 +3755,6 @@ ipmi_delloem_vFlash_main(struct ipmi_int
 	return rc;
 }
 /*
- * Function Name: 	get_vFlash_compcode_str
- *
- * Description: 	This function maps the vFlash completion code
- * 		to a string
- * Input : vFlash completion code and static array of codes vs strings
- * Output: -
- * Return: returns the mapped string
- */
-const char *
-get_vFlash_compcode_str(uint8_t vflashcompcode, const struct vFlashstr *vs)
-{
-	static char un_str[32];
-	int i;
-	for (i = 0; vs[i].str; i++) {
-		if (vs[i].val == vflashcompcode)
-			return vs[i].str;
-	}
-	memset(un_str, 0, 32);
-	snprintf(un_str, 32, "Unknown (0x%02X)", vflashcompcode);
-	return un_str;
-}
-/*
  * Function Name: 	ipmi_get_sd_card_info
  *
  * Description: This function prints the vFlash Extended SD card info
@@ -3822,7 +3798,7 @@ ipmi_get_sd_card_info(struct ipmi_intf *
 		return -1;
 	} else if (sdcardinfoblock->vflashcompcode != 0x00) {
 		lprintf(LOG_ERR, "Error in getting SD Card Extended Information (%s)",
-				get_vFlash_compcode_str(sdcardinfoblock->vflashcompcode,
+				val2str(sdcardinfoblock->vflashcompcode,
 					vFlash_completion_code_vals));
 		return -1;
 	}
