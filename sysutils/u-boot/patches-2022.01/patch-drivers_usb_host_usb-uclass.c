$NetBSD: patch-drivers_usb_host_usb-uclass.c,v 1.1 2022/02/11 21:46:14 mrg Exp $

Disable USB.  Hangs in usb_stop() / 'usb stop', if started.

Should be obsoleted by upstream:
  https://source.denx.de/u-boot/u-boot/-/commit/226fce6108fe364e35f3eb9a84ff1a7ec93727ce
but this breaks the USB3 port on RockPro64 and Pinebook Pro.

--- drivers/usb/host/usb-uclass.c.orig	2021-07-05 08:11:28.000000000 -0700
+++ drivers/usb/host/usb-uclass.c	2021-07-24 12:49:38.736439999 -0700
@@ -173,6 +173,15 @@
 
 int usb_stop(void)
 {
+#if 1
+	/*
+	 * XXXMRG
+	 *
+	 * This hangs when called either from EFI's ExitBootServices() or
+	 * explicit call to usb_stop(), say "usb stop" from the command prompt.
+	 */
+	printf("Not doing usb_stop().\n");
+#else
 	struct udevice *bus;
 	struct udevice *rh;
 	struct uclass *uc;
@@ -211,6 +220,7 @@
 	usb_started = 0;
 
 	return err;
+#endif
 }
 
 static void usb_scan_bus(struct udevice *bus, bool recurse)
