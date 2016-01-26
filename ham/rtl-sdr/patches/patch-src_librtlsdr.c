$NetBSD: patch-src_librtlsdr.c,v 1.1 2016/01/26 09:10:39 dbj Exp $

--- src/librtlsdr.c.orig	2014-02-07 01:04:24.000000000 +0000
+++ src/librtlsdr.c
@@ -39,6 +39,12 @@
 #define LIBUSB_CALL
 #endif
 
+/* libusb < 1.0.9 doesn't have libusb_handle_events_timeout_completed */
+#ifndef HAVE_LIBUSB_HANDLE_EVENTS_TIMEOUT_COMPLETED
+#define libusb_handle_events_timeout_completed(ctx, tv, c) \
+	libusb_handle_events_timeout(ctx, tv)
+#endif
+
 /* two raised to the power of n */
 #define TWO_POW(n)		((double)(1ULL<<(n)))
 
@@ -1776,11 +1782,8 @@ int rtlsdr_read_async(rtlsdr_dev_t *dev,
 	}
 
 	while (RTLSDR_INACTIVE != dev->async_status) {
-#ifdef HAVE_LIBUSB_HANDLE_EVENTS_TIMEOUT_COMPLETED
-		r = libusb_handle_events_timeout_completed(dev->ctx, &tv, &dev->async_cancel);
-#else
-		r = libusb_handle_events_timeout(dev->ctx, &tv);
-#endif
+		r = libusb_handle_events_timeout_completed(dev->ctx, &tv,
+							   &dev->async_cancel);
 		if (r < 0) {
 			/*fprintf(stderr, "handle_events returned: %d\n", r);*/
 			if (r == LIBUSB_ERROR_INTERRUPTED) /* stray signal */
@@ -1801,6 +1804,11 @@ int rtlsdr_read_async(rtlsdr_dev_t *dev,
 				if (LIBUSB_TRANSFER_CANCELLED !=
 						dev->xfer[i]->status) {
 					r = libusb_cancel_transfer(dev->xfer[i]);
+					/* handle events after canceling
+					 * to allow transfer status to
+					 * propagate */
+					libusb_handle_events_timeout_completed(dev->ctx,
+									       &zerotv, NULL);
 					if (r < 0)
 						continue;
 
@@ -1812,11 +1820,8 @@ int rtlsdr_read_async(rtlsdr_dev_t *dev,
 				/* handle any events that still need to
 				 * be handled before exiting after we
 				 * just cancelled all transfers */
-#ifdef HAVE_LIBUSB_HANDLE_EVENTS_TIMEOUT_COMPLETED
-				libusb_handle_events_timeout_completed(dev->ctx, &zerotv, NULL);
-#else
-				libusb_handle_events_timeout(dev->ctx, &zerotv);
-#endif
+				libusb_handle_events_timeout_completed(dev->ctx,
+								       &zerotv, NULL);
 				break;
 			}
 		}
