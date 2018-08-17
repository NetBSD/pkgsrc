$NetBSD: patch-src_burn_drv_pst90s_d__raiden2.cpp,v 1.1 2018/08/17 12:54:48 nia Exp $

Fixing Raiden 2 ARM issue (#198)

Upstream commit: bfc1f2fa0a9ca41add7858ba3badfa49257ec069

--- src/burn/drv/pst90s/d_raiden2.cpp.orig	2018-04-08 06:33:58.000000000 +0000
+++ src/burn/drv/pst90s/d_raiden2.cpp
@@ -802,7 +802,7 @@ static void cop_cmd_write(INT32 offset,
 			cop_status |= 0x8000;
 			cop_angle = 0;
 		} else {
-			cop_angle = (UINT16)(atan(double(dx)/double(dy)) * 128 / M_PI);
+			cop_angle = (INT32)(atan(double(dx)/double(dy)) * 128 / M_PI);
 			if(dy<0)
 				cop_angle += 0x80;
 		}
@@ -822,7 +822,7 @@ static void cop_cmd_write(INT32 offset,
 			cop_status |= 0x8000;
 			cop_angle = 0;
 		} else {
-			cop_angle = (UINT16)(atan(double(dx)/double(dy)) * 128 / M_PI);
+			cop_angle = (INT32)(atan(double(dx)/double(dy)) * 128 / M_PI);
 			if(dy<0)
 				cop_angle += 0x80;
 		}
