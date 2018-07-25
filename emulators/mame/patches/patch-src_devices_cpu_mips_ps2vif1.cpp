$NetBSD: patch-src_devices_cpu_mips_ps2vif1.cpp,v 1.1 2018/07/25 14:05:53 wiz Exp $

Fix namespace problems.

--- src/devices/cpu/mips/ps2vif1.cpp.orig	2018-07-24 19:45:05.000000000 +0000
+++ src/devices/cpu/mips/ps2vif1.cpp
@@ -622,5 +622,5 @@ uint32_t ps2_vif1_device::calculate_unpa
 		num = cl * (num / wl) + ((mod > cl) ? cl : mod);
 	}
 
-	return (uint32_t)std::ceil(((32 >> vl) * (vn + 1) * num) / 32.0f);
+	return (uint32_t)::ceil(((32 >> vl) * (vn + 1) * num) / 32.0f);
 }
