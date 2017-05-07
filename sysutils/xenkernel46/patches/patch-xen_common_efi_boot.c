$NetBSD: patch-xen_common_efi_boot.c,v 1.1 2017/05/07 21:21:01 joerg Exp $

--- xen/common/efi/boot.c.orig	2016-06-20 12:08:22.000000000 +0000
+++ xen/common/efi/boot.c
@@ -241,53 +241,33 @@ static void __init noreturn blexit(const
 /* generic routine for printing error messages */
 static void __init PrintErrMesg(const CHAR16 *mesg, EFI_STATUS ErrCode)
 {
+    static const CHAR16* const ErrCodeToStr[] __initconstrel = {
+        [~EFI_ERROR_MASK & EFI_NOT_FOUND]           = L"Not found",
+        [~EFI_ERROR_MASK & EFI_NO_MEDIA]            = L"The device has no media",
+        [~EFI_ERROR_MASK & EFI_MEDIA_CHANGED]       = L"Media changed",
+        [~EFI_ERROR_MASK & EFI_DEVICE_ERROR]        = L"Device error",
+        [~EFI_ERROR_MASK & EFI_VOLUME_CORRUPTED]    = L"Volume corrupted",
+        [~EFI_ERROR_MASK & EFI_ACCESS_DENIED]       = L"Access denied",
+        [~EFI_ERROR_MASK & EFI_OUT_OF_RESOURCES]    = L"Out of resources",
+        [~EFI_ERROR_MASK & EFI_VOLUME_FULL]         = L"Volume is full",
+        [~EFI_ERROR_MASK & EFI_SECURITY_VIOLATION]  = L"Security violation",
+        [~EFI_ERROR_MASK & EFI_CRC_ERROR]           = L"CRC error",
+        [~EFI_ERROR_MASK & EFI_COMPROMISED_DATA]    = L"Compromised data",
+        [~EFI_ERROR_MASK & EFI_BUFFER_TOO_SMALL]    = L"Buffer too small",
+    };
+    EFI_STATUS ErrIdx = ErrCode & ~EFI_ERROR_MASK;
+
     StdOut = StdErr;
     PrintErr((CHAR16 *)mesg);
     PrintErr(L": ");
 
-    switch (ErrCode)
+    if( (ErrIdx < ARRAY_SIZE(ErrCodeToStr)) && ErrCodeToStr[ErrIdx] )
+        mesg = ErrCodeToStr[ErrIdx];
+    else
     {
-    case EFI_NOT_FOUND:
-        mesg = L"Not found";
-        break;
-    case EFI_NO_MEDIA:
-        mesg = L"The device has no media";
-        break;
-    case EFI_MEDIA_CHANGED:
-        mesg = L"Media changed";
-        break;
-    case EFI_DEVICE_ERROR:
-        mesg = L"Device error";
-        break;
-    case EFI_VOLUME_CORRUPTED:
-        mesg = L"Volume corrupted";
-        break;
-    case EFI_ACCESS_DENIED:
-        mesg = L"Access denied";
-        break;
-    case EFI_OUT_OF_RESOURCES:
-        mesg = L"Out of resources";
-        break;
-    case EFI_VOLUME_FULL:
-        mesg = L"Volume is full";
-        break;
-    case EFI_SECURITY_VIOLATION:
-        mesg = L"Security violation";
-        break;
-    case EFI_CRC_ERROR:
-        mesg = L"CRC error";
-        break;
-    case EFI_COMPROMISED_DATA:
-        mesg = L"Compromised data";
-        break;
-    case EFI_BUFFER_TOO_SMALL:
-        mesg = L"Buffer too small";
-        break;
-    default:
         PrintErr(L"ErrCode: ");
         DisplayUint(ErrCode, 0);
         mesg = NULL;
-        break;
     }
     blexit(mesg);
 }
