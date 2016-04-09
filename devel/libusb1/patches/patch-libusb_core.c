$NetBSD: patch-libusb_core.c,v 1.1 2016/04/09 08:18:58 richard Exp $

prepare SunOS backend support

--- libusb/core.c.orig	2015-09-05 17:30:43.000000000 +0000
+++ libusb/core.c
@@ -58,6 +58,8 @@ const struct usbi_os_backend * const usb
 const struct usbi_os_backend * const usbi_backend = &wince_backend;
 #elif defined(OS_HAIKU)
 const struct usbi_os_backend * const usbi_backend = &haiku_usb_raw_backend;
+#elif defined(OS_SUNOS)
+const struct usbi_os_backend * const usbi_backend = &sunos_backend;
 #else
 #error "Unsupported OS"
 #endif
