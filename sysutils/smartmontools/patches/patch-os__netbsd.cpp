$NetBSD: patch-os__netbsd.cpp,v 1.2 2015/04/08 01:43:33 rodent Exp $

Use a raw disk device file on NetBSD.

--- os_netbsd.cpp.orig	2013-03-29 20:17:03.000000000 +0000
+++ os_netbsd.cpp
@@ -57,7 +57,7 @@ printwarning(int msgNo, const char *extr
   return;
 }
 
-static const char *net_dev_prefix = "/dev/";
+static const char *net_dev_prefix = "/dev/r";
 static const char *net_dev_ata_disk = "wd";
 static const char *net_dev_scsi_disk = "sd";
 static const char *net_dev_scsi_tape = "enrst";
