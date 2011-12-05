$NetBSD: patch-src_Stk500.C,v 1.1 2011/12/05 22:44:08 joerg Exp $

--- src/Stk500.C.orig	2011-12-05 20:37:56.000000000 +0000
+++ src/Stk500.C
@@ -407,7 +407,7 @@ void TStk500::FlushWriteBuffer(){
   }
 
   pgsz = prg_part[desired_part].params.pagesize;
-  pagesize = (pgsz[0]) << 8 + pgsz[1];
+  pagesize = (pgsz[0] << 8) + pgsz[1];
 
   if (pagesize == 0) {
     pagesize = 128;
