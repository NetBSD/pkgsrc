$NetBSD: patch-src_jtag_drivers_ulink.c,v 1.1 2015/04/23 12:21:19 rodent Exp $

"Remove useless checks causing build failure with clang". --upstream

--- src/jtag/drivers/ulink.c.orig	2014-03-29 16:55:12.000000000 +0000
+++ src/jtag/drivers/ulink.c
@@ -461,9 +461,6 @@ int ulink_write_firmware_section(struct 
 	LOG_DEBUG("section %02i at addr 0x%04x (size 0x%04x)", section_index, addr,
 		size);
 
-	if (data == NULL)
-		return ERROR_FAIL;
-
 	/* Copy section contents to local buffer */
 	ret = image_read_section(firmware_image, section_index, 0, size, data,
 			&size_read);
