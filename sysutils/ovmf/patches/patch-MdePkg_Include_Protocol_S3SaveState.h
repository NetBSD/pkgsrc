$NetBSD: patch-MdePkg_Include_Protocol_S3SaveState.h,v 1.1 2018/12/27 15:12:36 joerg Exp $

--- MdePkg/Include/Protocol/S3SaveState.h.orig	2018-12-26 00:12:22.128940406 +0000
+++ MdePkg/Include/Protocol/S3SaveState.h
@@ -52,7 +52,7 @@ typedef
 EFI_STATUS
 (EFIAPI *EFI_S3_SAVE_STATE_WRITE)(
    IN CONST EFI_S3_SAVE_STATE_PROTOCOL  *This,
-   IN       UINT16                      OpCode,
+   IN       int                         OpCode,
    ...
 );
 
@@ -98,7 +98,7 @@ EFI_STATUS
    IN CONST EFI_S3_SAVE_STATE_PROTOCOL  *This,
    IN       BOOLEAN                     BeforeOrAfter,
    IN OUT   EFI_S3_BOOT_SCRIPT_POSITION *Position       OPTIONAL,
-   IN       UINT16                      OpCode,
+   IN       int                         OpCode,
    ...
 );
 
