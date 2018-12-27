$NetBSD: patch-MdePkg_Include_Library_UefiLib.h,v 1.1 2018/12/27 15:12:36 joerg Exp $

--- MdePkg/Include/Library/UefiLib.h.orig	2018-12-26 00:00:48.975229808 +0000
+++ MdePkg/Include/Library/UefiLib.h
@@ -818,7 +818,7 @@ CHAR8 *
 EFIAPI
 GetBestLanguage (
   IN CONST CHAR8  *SupportedLanguages, 
-  IN BOOLEAN      Iso639Language,
+  IN int      Iso639Language,
   ...
   );
 
