$NetBSD: patch-src_flash_nor_sim3x.c,v 1.1 2015/10/07 23:14:47 joerg Exp $

--- src/flash/nor/sim3x.c.orig	2015-10-07 23:01:45.000000000 +0000
+++ src/flash/nor/sim3x.c
@@ -864,14 +864,12 @@ static int sim3x_flash_info(struct flash
 				return ERROR_BUF_TOO_SMALL;
 
 			/* Package */
-			if (sim3x_info->device_package) {
-				printed = snprintf(buf, buf_size, "-G%s", sim3x_info->device_package);
-				buf += printed;
-				buf_size -= printed;
+			printed = snprintf(buf, buf_size, "-G%s", sim3x_info->device_package);
+			buf += printed;
+			buf_size -= printed;
 
-				if (buf_size <= 0)
-					return ERROR_BUF_TOO_SMALL;
-			}
+			if (buf_size <= 0)
+				return ERROR_BUF_TOO_SMALL;
 		}
 	}
 
