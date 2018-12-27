$NetBSD: patch-MdeModulePkg_Universal_Variable_RuntimeDxe_Variable.c,v 1.1 2018/12/27 15:12:36 joerg Exp $

--- MdeModulePkg/Universal/Variable/RuntimeDxe/Variable.c.orig	2018-12-26 00:13:45.733084228 +0000
+++ MdeModulePkg/Universal/Variable/RuntimeDxe/Variable.c
@@ -1611,7 +1611,7 @@ CHAR8 *
 EFIAPI
 VariableGetBestLanguage (
   IN CONST CHAR8  *SupportedLanguages,
-  IN BOOLEAN      Iso639Language,
+  IN int          Iso639Language,
   ...
   )
 {
