$NetBSD: patch-libusb_os_netbsd__usb.c,v 1.4 2020/04/03 20:39:03 nia Exp $

* Set structure values by name
* Do not emit log messages from netbsd_clock_gettime as it is called from
  the logger.
* Translate EWOULDBLOCK (ugen timeouts) errors to LIBUSB_ERROR_TIMEOUT.

--- libusb/os/netbsd_usb.c.orig	2019-08-09 16:39:49.000000000 +0000
+++ libusb/os/netbsd_usb.c
@@ -87,55 +87,35 @@ static int _sync_gen_transfer(struct usb
 static int _access_endpoint(struct libusb_transfer *);
 
 const struct usbi_os_backend usbi_backend = {
-	"Synchronous NetBSD backend",
-	0,
-	NULL,				/* init() */
-	NULL,				/* exit() */
-	NULL,				/* set_option() */
-	netbsd_get_device_list,
-	NULL,				/* hotplug_poll */
-	netbsd_open,
-	netbsd_close,
-
-	netbsd_get_device_descriptor,
-	netbsd_get_active_config_descriptor,
-	netbsd_get_config_descriptor,
-	NULL,				/* get_config_descriptor_by_value() */
-
-	netbsd_get_configuration,
-	netbsd_set_configuration,
-
-	netbsd_claim_interface,
-	netbsd_release_interface,
-
-	netbsd_set_interface_altsetting,
-	netbsd_clear_halt,
-	netbsd_reset_device,
-
-	NULL,				/* alloc_streams */
-	NULL,				/* free_streams */
-
-	NULL,				/* dev_mem_alloc() */
-	NULL,				/* dev_mem_free() */
-
-	NULL,				/* kernel_driver_active() */
-	NULL,				/* detach_kernel_driver() */
-	NULL,				/* attach_kernel_driver() */
-
-	netbsd_destroy_device,
-
-	netbsd_submit_transfer,
-	netbsd_cancel_transfer,
-	netbsd_clear_transfer_priv,
-
-	NULL,				/* handle_events() */
-	netbsd_handle_transfer_completion,
-
-	netbsd_clock_gettime,
-	0,				/* context_priv_size */
-	sizeof(struct device_priv),
-	sizeof(struct handle_priv),
-	0,				/* transfer_priv_size */
+	.name = "Synchronous NetBSD backend",
+	.get_device_list = netbsd_get_device_list,
+	.open = netbsd_open,
+	.close = netbsd_close,
+
+	.get_device_descriptor = netbsd_get_device_descriptor,
+	.get_active_config_descriptor = netbsd_get_active_config_descriptor,
+	.get_config_descriptor = netbsd_get_config_descriptor,
+
+	.get_configuration = netbsd_get_configuration,
+	.set_configuration = netbsd_set_configuration,
+
+	.claim_interface = netbsd_claim_interface,
+	.release_interface = netbsd_release_interface,
+
+	.set_interface_altsetting = netbsd_set_interface_altsetting,
+	.clear_halt = netbsd_clear_halt,
+	.reset_device = netbsd_reset_device,
+	.destroy_device = netbsd_destroy_device,
+
+	.submit_transfer = netbsd_submit_transfer,
+	.cancel_transfer = netbsd_cancel_transfer,
+	.clear_transfer_priv = netbsd_clear_transfer_priv,
+
+	.handle_transfer_completion = netbsd_handle_transfer_completion,
+
+	.clock_gettime = netbsd_clock_gettime,
+	.device_priv_size = sizeof(struct device_priv),
+	.device_handle_priv_size = sizeof(struct handle_priv),
 };
 
 int
@@ -498,8 +478,6 @@ netbsd_handle_transfer_completion(struct
 int
 netbsd_clock_gettime(int clkid, struct timespec *tp)
 {
-	usbi_dbg("clock %d", clkid);
-
 	if (clkid == USBI_CLOCK_REALTIME)
 		return clock_gettime(CLOCK_REALTIME, tp);
 
@@ -521,6 +499,9 @@ _errno_to_libusb(int err)
 		return (LIBUSB_ERROR_NO_DEVICE);
 	case ENOMEM:
 		return (LIBUSB_ERROR_NO_MEM);
+	case EWOULDBLOCK:
+	case ETIMEDOUT:
+		return (LIBUSB_ERROR_TIMEOUT);
 	}
 
 	usbi_dbg("error: %s", strerror(err));
