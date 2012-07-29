$NetBSD: patch-grub-core_lib_posix__wrap_wchar.h,v 1.1 2012/07/29 21:44:13 gsutre Exp $

Include stddef rather than defining wchar_t to avoid conflict.

--- grub-core/lib/posix_wrap/wchar.h.orig	2012-02-08 20:34:24.000000000 +0000
+++ grub-core/lib/posix_wrap/wchar.h
@@ -29,7 +29,11 @@ enum
   };
 
 /* UCS-4.  */
+#if !defined(__NetBSD__)
 typedef grub_int32_t wchar_t;
+#else
+#include <stddef.h>
+#endif
 
 typedef struct mbstate {
   grub_uint32_t code;
