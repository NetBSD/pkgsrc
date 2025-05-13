$NetBSD: patch-iodev_display_voodoo__func.h,v 1.1 2025/05/13 15:48:55 nia Exp $

BX_BIG_ENDIAN is defined without a value, so the correct thing for this to
build properly on big endian is to use #ifdef.

--- iodev/display/voodoo_func.h.orig	2025-05-13 15:47:17.688415163 +0000
+++ iodev/display/voodoo_func.h
@@ -1627,7 +1627,7 @@ void voodoo2_bitblt_cpu_to_screen(Bit32u
     if (rgbfmt & 1) {
       BX_ERROR(("Voodoo bitBLT: color order other than RGB not supported yet"));
     }
-#if BX_BIG_ENDIAN
+#ifdef BX_BIG_ENDIAN
     data = bx_bswap32(data);
 #endif
     src_ptr = (Bit8u*)&data;
