$NetBSD: patch-src_common_platform.ads,v 1.1 2025/07/28 07:00:55 dkazankov Exp $

Add NetBSD support

--- src/common/platform.ads.orig	2024-01-11 17:55:20.000000000 +0200
+++ src/common/platform.ads
@@ -30,7 +30,8 @@
 
    type Host_Operating_System_Flavor is
       (X86_Windows, X86_64_Windows, X86_Linux, X86_64_Linux, X86_64_Darwin,
-       X86_64_FreeBSD, CodePeer_OS, AArch64_Darwin, AArch64_Linux);
+       X86_64_FreeBSD, CodePeer_OS, AArch64_Darwin, AArch64_Linux,
+       X86_64_NetBSD);
 
    function Get_OS_Flavor return Host_Operating_System_Flavor;
 
