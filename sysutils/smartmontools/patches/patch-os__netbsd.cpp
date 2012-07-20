$NetBSD: patch-os__netbsd.cpp,v 1.1 2012/07/20 12:35:00 taca Exp $

Use a raw disk device file on NetBSD.

--- os_netbsd.cpp.orig	2009-07-15 19:59:19.000000000 +0000
+++ os_netbsd.cpp
@@ -55,7 +55,7 @@ printwarning(int msgNo, const char *extr
   return;
 }
 
-static const char *net_dev_prefix = "/dev/";
+static const char *net_dev_prefix = "/dev/r";
 static const char *net_dev_ata_disk = "wd";
 static const char *net_dev_scsi_disk = "sd";
 static const char *net_dev_scsi_tape = "enrst";
