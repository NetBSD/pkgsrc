$NetBSD: patch-src_Stk500.C,v 1.1.36.1 2016/05/23 05:13:13 bsiegert Exp $

--- src/Stk500.C.orig	2004-02-07 19:12:33.000000000 +0000
+++ src/Stk500.C
@@ -393,7 +393,6 @@ void TStk500::WriteByte(TAddr addr, TByt
 void TStk500::FlushWriteBuffer(){
   TByte buf[0x200];
   int wordsize;
-  TAddr addr;
   TByte seg;
   const TByte *pgsz;
   int pagesize;
@@ -407,7 +406,7 @@ void TStk500::FlushWriteBuffer(){
   }
 
   pgsz = prg_part[desired_part].params.pagesize;
-  pagesize = (pgsz[0]) << 8 + pgsz[1];
+  pagesize = (pgsz[0] << 8) + pgsz[1];
 
   if (pagesize == 0) {
     pagesize = 128;
@@ -415,7 +414,6 @@ void TStk500::FlushWriteBuffer(){
 
   EnterProgrammingMode();
 
-  addr = 0;
   for (unsigned int addr=0; addr<maxaddr; addr+=pagesize) {
     memcpy(buf, SetAddress, sizeof(SetAddress));
     buf[1] = (addr/wordsize) & 0xff;
@@ -506,7 +504,7 @@ TByte TStk500::ReadLockBits()
 
 TByte TStk500::ReadCalFuseBits(int addr)
 {
-  TByte cmd[] = { 0x38, 0x00, addr, 0x00 };
+  TByte cmd[] = { 0x38, 0x00, TByte(addr), 0x00 };
 
   return UniversalCmd(cmd);
 }
@@ -712,7 +710,6 @@ void TStk500::ReadSignature() {
 void TStk500::ReadMem(){
   TByte buf[0x200];
   int wordsize;
-  TAddr addr;
   TByte seg;
 
   if (segment == SEG_FLASH) {
@@ -729,7 +726,6 @@ void TStk500::ReadMem(){
 
   EnterProgrammingMode();
 
-  addr = 0;
   for (unsigned int addr=0; addr<GetSegmentSize(); addr+=0x100) {
     memcpy(buf, SetAddress, sizeof(SetAddress));
     buf[1] = (addr/wordsize) & 0xff;
