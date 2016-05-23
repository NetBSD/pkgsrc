$NetBSD: patch-src_AvrAtmel.C,v 1.1.2.2 2016/05/23 05:13:13 bsiegert Exp $

--- src/AvrAtmel.C.orig	2016-05-18 12:28:24.000000000 +0000
+++ src/AvrAtmel.C
@@ -185,7 +185,7 @@ void TAvrAtmel::EnableAvr(){
 
 void TAvrAtmel::SetAddress(TAddr addr){
   apc_address = addr;
-  TByte setAddr [3] = { 'A', (addr>>8)&0xff, addr&0xff};
+  TByte setAddr [3] = { 'A', TByte((addr>>8)&0xff), TByte(addr&0xff)};
   Send(setAddr, 3, 1);
   CheckResponse(setAddr [0]);
 }
@@ -294,7 +294,7 @@ void TAvrAtmel::WriteByte(TAddr addr, TB
       if (flush_buffer){WriteProgramMemoryPage();}
     }
     
-    TByte wrF [2] = { (addr&1)?'C':'c', byte };
+    TByte wrF [2] = { TByte((addr&1)?'C':'c'), byte };
     
     if (apc_address!=(addr>>1) || apc_autoinc==false) SetAddress (addr>>1);
     if (wrF[0]=='C') apc_address++;
@@ -346,7 +346,7 @@ void TAvrAtmel::WriteByte(TAddr addr, TB
  */
 void TAvrAtmel::WriteOldFuseBits (TByte val)
 {
-  TByte buf[5] = {'.', 0xac, (val & 0x1f) | 0xa0, 0x00, 0xd2 };
+  TByte buf[5] = {'.', 0xac, TByte((val & 0x1f) | 0xa0), 0x00, 0xd2 };
   Info (2, "Write fuse high bits: %02x\n", (int)val);
   Send (buf, 5, 2);
   CheckResponse (buf[1]);
@@ -423,7 +423,7 @@ void TAvrAtmel::ChipErase(){
 }
 
 void TAvrAtmel::WriteLockBits(TByte bits){
-  TByte lockTarget [2] = { 'l', 0xF9 | ((bits << 1) & 0x06) };
+  TByte lockTarget [2] = { 'l', TByte(0xF9 | ((bits << 1) & 0x06)) };
   Send (lockTarget, 2, 1);
   CheckResponse(lockTarget [0]);
   Info(1, "Writing lock bits ...\nReinitializing device\n");
