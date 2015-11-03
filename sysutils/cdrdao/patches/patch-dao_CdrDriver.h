$NetBSD: patch-dao_CdrDriver.h,v 1.1 2015/11/03 19:08:45 joerg Exp $

--- dao/CdrDriver.h.orig	2015-11-03 11:24:08.000000000 +0000
+++ dao/CdrDriver.h
@@ -440,7 +440,7 @@ protected:
   bool fullBurn_;
 
   static unsigned char syncPattern[12];
-  static char REMOTE_MSG_SYNC_[4];
+  static unsigned char REMOTE_MSG_SYNC_[4];
 
   static int speed2Mult(int);
   static int mult2Speed(int);
