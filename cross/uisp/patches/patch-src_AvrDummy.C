$NetBSD: patch-src_AvrDummy.C,v 1.1.2.2 2016/05/23 05:13:13 bsiegert Exp $

--- src/AvrDummy.C.orig	2016-05-18 12:26:28.000000000 +0000
+++ src/AvrDummy.C
@@ -81,12 +81,12 @@ TByte
 TAvrDummy::GetPartInfo(TAddr addr)
 {
   if (at89) {
-    TByte info [4] = { 0x28, addr & 0x1f, 0, 0 };
+    TByte info [4] = { 0x28, TByte(addr & 0x1f), 0, 0 };
     Send(info, 4);
     return info[3];
   }
 
-  TByte info [4] = { 0x30, 0, addr, 0 };
+  TByte info [4] = { 0x30, 0, TByte(addr), 0 };
   Send(info, 4);
   return info[3];
 }
@@ -289,7 +289,7 @@ TAvrDummy::ReadCalByte(TByte addr)
 void
 TAvrDummy::WriteOldFuseBits(TByte val)
 {
-  TByte oldfuse[4] = { 0xAC, (val & 0x1F) | 0xA0, 0, 0xD2 };
+  TByte oldfuse[4] = { 0xAC, TByte((val & 0x1F) | 0xA0), 0, 0xD2 };
   Send(oldfuse, 4);
 }
 
@@ -532,7 +532,7 @@ TAvrDummy::WriteLockBits(TByte bits)
 {
   /* This handles both old (byte 2, bits 1-2)
      and new (byte 4, bits 0-5) devices.  */
-  TByte lock[4] = { 0xAC, 0xF9 | ((bits << 1) & 0x06), 0xFF, bits };
+  TByte lock[4] = { 0xAC, TByte(0xF9 | ((bits << 1) & 0x06)), 0xFF, bits };
   TByte rbits;
 
   if (at89)
