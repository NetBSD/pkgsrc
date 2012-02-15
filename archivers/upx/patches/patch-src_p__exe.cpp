$NetBSD: patch-src_p__exe.cpp,v 1.1 2012/02/15 19:27:10 hans Exp $

--- src/p_exe.cpp.orig	2004-03-25 06:36:19.000000000 +0100
+++ src/p_exe.cpp	2012-01-11 15:35:13.755302407 +0100
@@ -347,7 +347,7 @@ void PackExe::pack(OutputFile *fo)
     {
         set_le16(extra_info+eisize,ih.ss);
         eisize += 2;
-        flag |= SS;
+        flag |= upx_SS;
     }
     if (oh.sp != ih.sp)
     {
@@ -413,7 +413,7 @@ void PackExe::pack(OutputFile *fo)
                   NULL
                  );
     addLoader("EXEMAIN8",
-              (flag & SS) ? "EXESTACK" : "",
+              (flag & upx_SS) ? "EXESTACK" : "",
               (flag & SP) ? "EXESTASP" : "",
               (flag & USEJUMP) ? "EXEJUMPF" : "",
               NULL
@@ -480,7 +480,7 @@ void PackExe::pack(OutputFile *fo)
     }
     if (flag & SP)
         patch_le16(loader,lsize,"SP",ih.sp);
-    if (flag & SS)
+    if (flag & upx_SS)
         patch_le16(loader,lsize,"SS",ih.ss);
     if (relocsize)
         patch_le16(loader,lsize,"RS",(ph.u_len <= DI_LIMIT || (ph.u_len & 0x7fff) >= relocsize ? 0 : MAXRELOCS) - relocsize);
@@ -654,7 +654,7 @@ void PackExe::unpack(OutputFile *fo)
         { imagesize -= 2; oh.min = get_le16(ibuf+imagesize); }
     if (flag & SP)
         { imagesize -= 2; oh.sp = get_le16(ibuf+imagesize); }
-    if (flag & SS)
+    if (flag & upx_SS)
         { imagesize -= 2; oh.ss = get_le16(ibuf+imagesize); }
 
     unsigned ip = (flag & USEJUMP) ? get_le32(ibuf+imagesize-4) : (unsigned) ih.firstreloc;
