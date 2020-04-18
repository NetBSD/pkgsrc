$NetBSD: patch-lib_sanitizer__common_sanitizer__platform__limits__netbsd.cpp,v 1.1 2020/04/18 08:03:53 adam Exp $

urio driver has been removed from NetBSD.

--- lib/sanitizer_common/sanitizer_platform_limits_netbsd.cpp.orig	2020-03-30 13:20:43.073033175 +0000
+++ lib/sanitizer_common/sanitizer_platform_limits_netbsd.cpp
@@ -190,7 +190,9 @@
 #include <dev/sun/vuid_event.h>
 #include <dev/tc/sticio.h>
 #include <dev/usb/ukyopon.h>
+#if __NetBSD_Version__ < 999000000
 #include <dev/usb/urio.h>
+#endif
 #include <dev/usb/usb.h>
 #include <dev/usb/utoppy.h>
 #include <dev/vme/xio.h>
@@ -702,7 +704,9 @@ unsigned struct_twe_drivecommand_sz = si
 unsigned struct_twe_paramcommand_sz = sizeof(twe_paramcommand);
 unsigned struct_twe_usercommand_sz = sizeof(twe_usercommand);
 unsigned struct_ukyopon_identify_sz = sizeof(ukyopon_identify);
+#if __NetBSD_Version__ < 999000000
 unsigned struct_urio_command_sz = sizeof(urio_command);
+#endif
 unsigned struct_usb_alt_interface_sz = sizeof(usb_alt_interface);
 unsigned struct_usb_bulk_ra_wb_opt_sz = sizeof(usb_bulk_ra_wb_opt);
 unsigned struct_usb_config_desc_sz = sizeof(usb_config_desc);
@@ -1291,8 +1295,10 @@ unsigned IOCTL_STICIO_RESET = STICIO_RES
 unsigned IOCTL_STICIO_STARTQ = STICIO_STARTQ;
 unsigned IOCTL_STICIO_STOPQ = STICIO_STOPQ;
 unsigned IOCTL_UKYOPON_IDENTIFY = UKYOPON_IDENTIFY;
+#if __NetBSD_Version__ < 999000000
 unsigned IOCTL_URIO_SEND_COMMAND = URIO_SEND_COMMAND;
 unsigned IOCTL_URIO_RECV_COMMAND = URIO_RECV_COMMAND;
+#endif
 unsigned IOCTL_USB_REQUEST = USB_REQUEST;
 unsigned IOCTL_USB_SETDEBUG = USB_SETDEBUG;
 unsigned IOCTL_USB_DISCOVER = USB_DISCOVER;
