$NetBSD: patch-src_p__exe.cpp,v 1.2 2012/05/02 06:45:14 adam Exp $

--- src/p_exe.cpp.orig	2011-12-12 16:08:00.000000000 +0000
+++ src/p_exe.cpp
@@ -110,7 +110,7 @@ int PackExe::fillExeHeader(struct exe_he
         oh.ss += 0x20;
 
     if (oh.ss != ih.ss)
-        flag |= SS;
+        flag |= upx_SS;
     if (oh.sp != ih.sp || M_IS_LZMA(ph.method))
         flag |= SP;
     return flag;
@@ -131,7 +131,7 @@ void PackExe::addLoaderEpilogue(int flag
                  );
     addLoader("EXEMAIN8",
               device_driver ? "DEVICEEND" : "",
-              (flag & SS) ? "EXESTACK" : "",
+              (flag & upx_SS) ? "EXESTACK" : "",
               (flag & SP) ? "EXESTASP" : "",
               (flag & USEJUMP) ? "EXEJUMPF" : "",
               NULL
@@ -556,7 +556,7 @@ void PackExe::pack(OutputFile *fo)
     {
         set_le16(extra_info+eisize,ih.ss);
         eisize += 2;
-        assert((flag & SS) != 0);   // set in fillExeHeader()
+        assert((flag & upx_SS) != 0);   // set in fillExeHeader()
     }
     if (oh.sp != ih.sp)
     {
@@ -779,7 +779,7 @@ void PackExe::unpack(OutputFile *fo)
         { imagesize -= 2; oh.min = get_le16(ibuf+imagesize); }
     if (flag & SP)
         { imagesize -= 2; oh.sp = get_le16(ibuf+imagesize); }
-    if (flag & SS)
+    if (flag & upx_SS)
         { imagesize -= 2; oh.ss = get_le16(ibuf+imagesize); }
 
     unsigned ip = (flag & USEJUMP) ? get_le32(ibuf+imagesize-4) : (unsigned) ih.firstreloc;
