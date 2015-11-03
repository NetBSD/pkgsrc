$NetBSD: patch-dao_CdrDriver.cc,v 1.1 2015/11/03 19:08:45 joerg Exp $

--- dao/CdrDriver.cc.orig	2015-11-03 11:23:52.000000000 +0000
+++ dao/CdrDriver.cc
@@ -495,7 +495,7 @@ unsigned char CdrDriver::syncPattern[12]
   0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0
 };
 
-char CdrDriver::REMOTE_MSG_SYNC_[4] = { 0xff, 0x00, 0xff, 0x00 };
+unsigned char CdrDriver::REMOTE_MSG_SYNC_[4] = { 0xff, 0x00, 0xff, 0x00 };
 
 
 /* Maps a string to the corresponding driver option value 
