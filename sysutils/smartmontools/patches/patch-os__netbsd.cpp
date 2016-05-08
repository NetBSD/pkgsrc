$NetBSD: patch-os__netbsd.cpp,v 1.3 2016/05/08 11:23:15 nonaka Exp $

Use a raw disk device file on NetBSD.

--- os_netbsd.cpp.orig	2016-03-26 19:47:47.000000000 +0000
+++ os_netbsd.cpp	2016-05-08 06:45:25.000000000 +0000
@@ -54,7 +54,7 @@ printwarning(int msgNo, const char *extr
   return;
 }
 
-static const char *net_dev_prefix = "/dev/";
+static const char *net_dev_prefix = "/dev/r";
 static const char *net_dev_ata_disk = "wd";
 static const char *net_dev_scsi_disk = "sd";
 static const char *net_dev_scsi_tape = "enrst";
@@ -128,7 +128,7 @@ get_dev_names(char ***names, const char 
     n++;
   }
 
-  void * tmp = (char **)realloc(mp, n * (sizeof(char *)));
+  char ** tmp = (char **)realloc(mp, n * (sizeof(char *)));
   if (NULL == tmp) {
     pout("Out of memory constructing scan device list\n");
     free(mp);
