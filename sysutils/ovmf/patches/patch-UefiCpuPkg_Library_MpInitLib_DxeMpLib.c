$NetBSD: patch-UefiCpuPkg_Library_MpInitLib_DxeMpLib.c,v 1.1 2018/12/27 15:12:36 joerg Exp $

--- UefiCpuPkg/Library/MpInitLib/DxeMpLib.c.orig	2018-12-26 00:02:30.198168128 +0000
+++ UefiCpuPkg/Library/MpInitLib/DxeMpLib.c
@@ -244,7 +244,6 @@ GetProtectedModeCS (
     }
     GdtEntry++;
   }
-  ASSERT (Index != -1);
   return Index * 8;
 }
 
