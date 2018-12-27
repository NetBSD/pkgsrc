$NetBSD: patch-MdeModulePkg_Universal_Acpi_S3SaveStateDxe_S3SaveState.c,v 1.1 2018/12/27 15:12:36 joerg Exp $

--- MdeModulePkg/Universal/Acpi/S3SaveStateDxe/S3SaveState.c.orig	2018-12-26 00:07:03.569298328 +0000
+++ MdeModulePkg/Universal/Acpi/S3SaveStateDxe/S3SaveState.c
@@ -542,7 +542,7 @@ EFI_STATUS
 EFIAPI
 BootScriptWrite (
   IN CONST EFI_S3_SAVE_STATE_PROTOCOL      *This,
-  IN       UINT16                           OpCode,
+  IN       int                             OpCode,
   ...
   )
 {
@@ -697,7 +697,7 @@ BootScriptInsert (
   IN CONST EFI_S3_SAVE_STATE_PROTOCOL     *This,
   IN       BOOLEAN                        BeforeOrAfter,
   IN OUT   EFI_S3_BOOT_SCRIPT_POSITION    *Position OPTIONAL,
-  IN       UINT16                         OpCode,
+  IN       int                            OpCode,
   ...
   )
 {
