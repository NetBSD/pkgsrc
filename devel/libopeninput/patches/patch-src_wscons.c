$NetBSD: patch-src_wscons.c,v 1.2 2026/09/22 14:38:21 kikadf Exp $

* Handle attached-detached devices with udev monitor

--- src/wscons.c.orig	2026-08-29 17:19:47.000000000 +0000
+++ src/wscons.c
@@ -47,6 +47,126 @@ static void
 wscons_device_init_pointer_acceleration(struct wscons_device *device,
               struct motion_filter *filter);
 
+#if defined(__NetBSD__)
+static void
+wscons_udev_handler(void *data)
+{
+	struct udev_input *input = data;
+	struct udev_device *udev_device;
+	struct libinput_seat *seat;
+	struct libinput_device *device;
+	usec_t time;
+	struct timespec ts;
+	struct libinput_event *event;
+	const char *action, *devnode, *sysname;
+
+	udev_device = udev_monitor_receive_device(input->udev_monitor);
+	if (!udev_device)
+		return;
+
+	action = udev_device_get_action(udev_device);
+	devnode = udev_device_get_devnode(udev_device);
+	sysname = udev_device_get_sysname(udev_device);
+	if (!action || !devnode || !sysname)
+		goto out;
+
+	if (!(strneq(sysname, "wskbd", 5) || strneq(sysname, "wsmouse", 7)))
+		goto out;
+
+	if (streq(action, "add")) {
+		device = libinput_path_add_device(&input->base, devnode);
+		if (!device)
+			goto out;
+		clock_gettime(CLOCK_REALTIME, &ts);
+		time = usec_from_timespec(&ts);
+		event = calloc(1, sizeof(*event));
+		post_device_event(device, time, LIBINPUT_EVENT_DEVICE_ADDED, event);
+	}
+	else if (streq(action, "remove")) {
+		seat = wscons_seat_get(&input->base, default_seat, default_seat_name);
+		list_for_each(device, &seat->devices_list, link) {
+			if (device->devname && strcmp(device->devname, devnode) == 0) {
+				clock_gettime(CLOCK_REALTIME, &ts);
+				time = usec_from_timespec(&ts);
+				event = calloc(1, sizeof(*event));
+				post_device_event(device, time, LIBINPUT_EVENT_DEVICE_REMOVED, event);
+				libinput_path_remove_device(device);
+				break;
+			}
+		}
+	}
+
+out:
+	udev_device_unref(udev_device);
+}
+
+static int
+udev_input_enable(struct libinput *libinput)
+{
+	struct udev_input *input = (struct udev_input *)libinput;
+	struct udev *udev = input->udev;
+	int fd;
+
+	input->udev_monitor = udev_monitor_new_from_netlink(udev, "udev");
+	if (!input->udev_monitor) {
+		log_info(libinput, "udev: failed to create the udev monitor\n");
+		return -1;
+	}
+
+	if (udev_monitor_filter_add_match_subsystem_devtype(input->udev_monitor, "input", NULL)) {
+		log_info(libinput, "udev: failed to set up filter\n");
+		goto err;
+	}
+
+	if (udev_monitor_enable_receiving(input->udev_monitor)) {
+		log_info(libinput, "udev: failed to bind the udev monitor\n");
+		goto err;
+ 	}
+
+	fd = udev_monitor_get_fd(input->udev_monitor);
+	input->udev_monitor_source =
+			libinput_add_fd(&input->base, fd, wscons_udev_handler, input);
+	if (!input->udev_monitor_source) {
+		goto err;
+	}
+
+ 	return 0;
+
+err:
+	if (input->udev_monitor) {
+		udev_monitor_unref(input->udev_monitor);
+		input->udev_monitor = NULL;
+	}
+	return -1;
+}
+
+static void
+udev_input_disable(struct libinput *libinput)
+{
+	struct udev_input *input = (struct udev_input*)libinput;
+
+	if (input->udev_monitor_source) {
+		libinput_remove_source(&input->base, input->udev_monitor_source);
+		input->udev_monitor_source = NULL;
+	}
+	if (input->udev_monitor) {
+		udev_monitor_unref(input->udev_monitor);
+		input->udev_monitor = NULL;
+	}
+}
+
+static void
+udev_input_destroy(struct libinput *libinput)
+{
+	struct udev_input *input = (struct udev_input*)libinput;
+
+	if (input->udev) {
+		udev_unref(input->udev);
+		input->udev = NULL;
+	}
+}
+
+#else   // OpenBSD
 static int
 udev_input_enable(struct libinput *libinput)
 {
@@ -94,6 +214,7 @@ udev_input_destroy(struct libinput *libi
 		close_restricted(libinput, device->fd);
 	}
 }
+#endif  // if NetBSD else OpenBSD
 
 static int
 udev_device_change_seat(struct libinput_device *device,
@@ -303,6 +424,83 @@ wscons_seat_get(struct libinput *libinpu
 	return seat;
 }
 
+#if defined(__NetBSD__)
+LIBINPUT_EXPORT struct libinput *
+libinput_udev_create_context(const struct libinput_interface *interface,
+			     void *user_data,
+			     struct udev *udev)
+{
+	struct udev_input *input;
+
+	if (!interface || !udev)
+ 		return NULL;
+
+	input = calloc(1, sizeof(*input));
+	if (!input)
+		return NULL;
+
+	if (libinput_init(&input->base, interface, &interface_backend, user_data) != 0) {
+		libinput_unref(&input->base);
+		free(input);
+		return NULL;
+	}
+
+	input->udev = udev_ref(udev);
+
+	return &input->base;
+}
+
+LIBINPUT_EXPORT int
+libinput_udev_assign_seat(struct libinput *libinput, const char *seat_id)
+{
+	struct libinput_seat *seat;
+	struct libinput_device *device;
+	usec_t time;
+	struct timespec ts;
+	struct libinput_event *event;
+	struct udev_list_entry *entry;
+	struct udev_input *input = (struct udev_input*)libinput;
+	struct udev *udev = input->udev;
+
+	/* Add standard devices */
+	_unref_(udev_enumerate) *e = udev_enumerate_new(udev);
+	udev_enumerate_add_match_subsystem(e, "input");
+	udev_enumerate_scan_devices(e);
+	udev_list_entry_foreach(entry, udev_enumerate_get_list_entry(e)) {
+		const char *path = udev_list_entry_get_name(entry);
+		_unref_(udev_device) *device = udev_device_new_from_syspath(udev, path);
+		if (!device)
+			continue;
+
+		const char *sysname = udev_device_get_sysname(device);
+		if (!sysname ||
+		   (!strstartswith(sysname, "wskbd") &&
+		    !strstartswith(sysname, "wsmouse"))) {
+			continue;
+		}
+
+		const char *devnode = udev_device_get_devnode(device);
+		if (!devnode)
+			continue;
+		libinput_path_add_device(libinput, devnode);
+	}
+
+	seat = wscons_seat_get(libinput, default_seat, default_seat_name);
+	list_for_each(device, &seat->devices_list, link) {
+		clock_gettime(CLOCK_REALTIME, &ts);
+		time = usec_from_timespec(&ts);
+		event = calloc(1, sizeof(*event));
+		post_device_event(device, time, LIBINPUT_EVENT_DEVICE_ADDED,
+		    event);
+	}
+
+	if (udev_input_enable(&input->base) < 0)
+		return -1;
+
+	return 0;
+}
+
+#else   // OpenBSD
 LIBINPUT_EXPORT struct libinput *
 libinput_udev_create_context(const struct libinput_interface *interface,
 			     void *user_data,
@@ -357,6 +555,7 @@ libinput_udev_assign_seat(struct libinpu
 	}
 	return 0;
 }
+#endif  // if NetBSD else OpenBSD
 
 LIBINPUT_EXPORT struct libinput *
 libinput_path_create_context(const struct libinput_interface *interface,
@@ -554,6 +753,14 @@ wscons_device_init(struct wscons_device 
 	return 0;
 }
 
+void
+wscons_device_destroy(struct wscons_device *wscons_device)
+{
+	filter_destroy(wscons_device->pointer.filter);
+	free(wscons_device->base.devname);
+	free(wscons_device);
+}
+
 LIBINPUT_EXPORT struct libinput_device *
 libinput_path_add_device(struct libinput *libinput,
 	const char *path)
@@ -622,6 +829,7 @@ libinput_path_remove_device(struct libin
 {
 	struct libinput *libinput = device->seat->libinput;
 
+	list_remove(&device->link);
 	libinput_remove_source(libinput, device->source);
 	device->source = NULL;
 
