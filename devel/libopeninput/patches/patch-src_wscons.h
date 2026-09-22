$NetBSD: patch-src_wscons.h,v 1.2 2026/09/22 14:38:21 kikadf Exp $

* Handle attached-detached devices with udev monitor

--- src/wscons.h.orig	2026-08-29 17:19:47.000000000 +0000
+++ src/wscons.h
@@ -25,6 +25,14 @@ struct wscons_device {
 	} pointer;
 };
 
+#if defined(__NetBSD__)
+struct udev_input {
+	struct libinput base;
+	struct udev *udev;
+	struct udev_monitor *udev_monitor;
+	struct libinput_source *udev_monitor_source;
+};
+#endif
 
 static inline struct wscons_device *
 wscons_device(struct libinput_device *device)
@@ -32,6 +40,7 @@ wscons_device(struct libinput_device *de
 	return container_of(device, struct wscons_device, base);
 }
 extern int wscons_keyboard_init(struct wscons_device *);
+extern void wscons_device_destroy(struct wscons_device *);
 extern uint32_t wskey_transcode(struct TransMapRec *, int);
 extern void post_device_event(struct libinput_device *, usec_t ,
     enum libinput_event_type , struct libinput_event *);
