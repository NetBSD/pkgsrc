$NetBSD: patch-MdePkg_Library_UefiLib_UefiLib.c,v 1.1 2018/12/27 15:12:36 joerg Exp $

--- MdePkg/Library/UefiLib/UefiLib.c.orig	2018-12-25 23:59:03.914734061 +0000
+++ MdePkg/Library/UefiLib/UefiLib.c
@@ -1514,7 +1514,7 @@ CHAR8 *
 EFIAPI
 GetBestLanguage (
   IN CONST CHAR8  *SupportedLanguages, 
-  IN BOOLEAN      Iso639Language,
+  IN int      Iso639Language,
   ...
   )
 {
