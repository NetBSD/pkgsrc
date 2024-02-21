$NetBSD: patch-agent_mibgroup_if-mib_data__access_interface.h,v 1.2 2024/02/21 10:21:01 wiz Exp $

Improve portability to newer NetBSD versions.

--- agent/mibgroup/if-mib/data_access/interface.h.orig	2023-08-15 20:32:01.000000000 +0000
+++ agent/mibgroup/if-mib/data_access/interface.h
@@ -34,7 +34,8 @@ config_require(if-mib/data_access/interf
 config_require(if-mib/data_access/interface_ioctl);
 #elif defined( openbsd3 ) ||                                         \
     defined( freebsd4 ) || defined( freebsd5 ) || defined( freebsd6 ) || \
-    defined( darwin )   || defined( dragonfly ) || defined( netbsd1 )
+    defined( darwin )   || defined( dragonfly ) || defined( netbsd1 ) || \
+    defined(netbsd) || defined(netbsdelf) || defined(netbsdelf2) || defined(netbsdelf3)
 config_require(if-mib/data_access/interface_sysctl);
 #elif defined(solaris2)
 config_require(if-mib/data_access/interface_solaris2);
