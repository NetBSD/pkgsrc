$NetBSD: patch-src_usbhid-dump.c,v 1.1 2019/07/02 13:29:34 ryoon Exp $

* NetBSD has no device driver detach as of 2019-06-26

--- src/usbhid-dump.c.orig	2014-07-12 18:02:02.000000000 +0000
+++ src/usbhid-dump.c
@@ -549,8 +549,10 @@ run(bool            dump_descriptor,
     /* Detach and claim the interfaces */
     UHD_IFACE_LIST_FOR_EACH(iface, iface_list)
     {
+#if !defined(__NetBSD__)
         LIBUSB_IFACE_GUARD(uhd_iface_detach(iface),
                            iface, "detach from the kernel driver");
+#endif
         LIBUSB_IFACE_GUARD(uhd_iface_claim(iface),
                            iface, "claim");
     }
