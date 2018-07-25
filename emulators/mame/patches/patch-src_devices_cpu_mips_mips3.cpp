$NetBSD: patch-src_devices_cpu_mips_mips3.cpp,v 1.1 2018/07/25 14:05:53 wiz Exp $

Fix namespace problems.

--- src/devices/cpu/mips/mips3.cpp.orig	2018-07-24 19:45:05.000000000 +0000
+++ src/devices/cpu/mips/mips3.cpp
@@ -3053,7 +3053,7 @@ void r5900le_device::handle_extra_cop2(u
 				{
 					if (BIT(op, 24-field))
 					{
-						fd[field] = std::fmax(fs[field], ft[bc]);
+						fd[field] = ::fmax(fs[field], ft[bc]);
 					}
 				}
 			}
@@ -3069,7 +3069,7 @@ void r5900le_device::handle_extra_cop2(u
 				{
 					if (BIT(op, 24-field))
 					{
-						fd[field] = std::fmin(fs[field], ft[bc]);
+						fd[field] = ::fmin(fs[field], ft[bc]);
 					}
 				}
 			}
