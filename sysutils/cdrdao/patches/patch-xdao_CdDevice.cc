$NetBSD: patch-xdao_CdDevice.cc,v 1.1 2015/11/03 19:08:45 joerg Exp $

--- xdao/CdDevice.cc.orig	2015-11-03 11:26:42.000000000 +0000
+++ xdao/CdDevice.cc
@@ -255,7 +255,7 @@ int CdDevice::updateStatus()
 
 bool CdDevice::updateProgress(Glib::IOCondition cond, int fd)
 {
-  static char msgSync[4] = { 0xff, 0x00, 0xff, 0x00 };
+  static unsigned char msgSync[4] = { 0xff, 0x00, 0xff, 0x00 };
   fd_set fds;
   int state = 0;
   char buf[10];
