$NetBSD: patch-src_wscons.c,v 1.1 2026/04/13 15:19:37 kikadf Exp $

* Handle attached-detached devices with udev monitor

--- src/wscons.c.orig	2026-03-08 12:38:09.000000000 +0000
+++ src/wscons.c
@@ -46,51 +46,121 @@ static void
 wscons_device_init_pointer_acceleration(struct wscons_device *device,
               struct motion_filter *filter);
 
-static int
-udev_input_enable(struct libinput *libinput)
+static void
+wscons_udev_handler(void *data)
 {
+	struct udev_input *input = data;
+	struct udev_device *udev_device;
 	struct libinput_seat *seat;
 	struct libinput_device *device;
+	uint64_t time;
+	struct timespec ts;
+	struct libinput_event *event;
+	const char *action, *devnode, *sysname;
 
-	seat = wscons_seat_get(libinput, default_seat, default_seat_name);
-	list_for_each(device, &seat->devices_list, link) {
-		device->fd = open_restricted(libinput, device->devname, O_RDWR);
-		device->source =
-		    libinput_add_fd(libinput, device->fd,
-			wscons_device_dispatch, device);
-		if (!device->source) {
-			return -ENOMEM;
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
+		time = s2us(ts.tv_sec) + ns2us(ts.tv_nsec);
+		event = calloc(1, sizeof(*event));
+		post_device_event(device, time, LIBINPUT_EVENT_DEVICE_ADDED, event);
+	}
+	else if (streq(action, "remove")) {
+		seat = wscons_seat_get(&input->base, default_seat, default_seat_name);
+		list_for_each(device, &seat->devices_list, link) {
+			if (device->devname && strcmp(device->devname, devnode) == 0) {
+				clock_gettime(CLOCK_REALTIME, &ts);
+				time = s2us(ts.tv_sec) + ns2us(ts.tv_nsec);
+				event = calloc(1, sizeof(*event));
+				post_device_event(device, time, LIBINPUT_EVENT_DEVICE_REMOVED, event);
+				libinput_path_remove_device(device);
+				break;
+			}
 		}
 	}
-	return 0;
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
 }
 
 static void
 udev_input_disable(struct libinput *libinput)
 {
-	struct libinput_seat *seat;
-	struct libinput_device *device;
+	struct udev_input *input = (struct udev_input*)libinput;
 
-	seat = wscons_seat_get(libinput, default_seat, default_seat_name);
-	list_for_each(device, &seat->devices_list, link) {
-		if (device->source) {
-			libinput_remove_source(libinput, device->source);
-			device->source = NULL;
-		}
-		close_restricted(libinput, device->fd);
+	if (input->udev_monitor_source) {
+		libinput_remove_source(&input->base, input->udev_monitor_source);
+		input->udev_monitor_source = NULL;
+	}
+	if (input->udev_monitor) {
+		udev_monitor_unref(input->udev_monitor);
+		input->udev_monitor = NULL;
 	}
 }
 
 static void
 udev_input_destroy(struct libinput *libinput)
 {
-	struct libinput_seat *seat;
-	struct libinput_device *device;
+	struct udev_input *input = (struct udev_input*)libinput;
 
-	fprintf(stderr, "%s", __func__);
-	seat = wscons_seat_get(libinput, default_seat, default_seat_name);
-	list_for_each(device, &seat->devices_list, link) {
-		close_restricted(libinput, device->fd);
+	if (input->udev) {
+		udev_unref(input->udev);
+		input->udev = NULL;
 	}
 }
 
@@ -295,17 +365,24 @@ libinput_udev_create_context(const struc
 			     void *user_data,
 			     struct udev *udev)
 {
-	struct libinput *libinput;
+	struct udev_input *input;
 
-	libinput = calloc(1, sizeof(*libinput));
-	if (libinput == NULL)
+	if (!interface || !udev)
+ 		return NULL;
+
+	input = calloc(1, sizeof(*input));
+	if (!input)
 		return NULL;
 
-	if (libinput_init(libinput, interface, &interface_backend, user_data) != 0) {
-		free(libinput);
+	if (libinput_init(&input->base, interface, &interface_backend, user_data) != 0) {
+		libinput_unref(&input->base);
+		free(input);
 		return NULL;
 	}
-	return libinput;
+
+	input->udev = udev_ref(udev);
+
+	return &input->base;
 }
 
 LIBINPUT_EXPORT int
@@ -317,6 +394,7 @@ libinput_udev_assign_seat(struct libinpu
 	uint64_t time;
 	struct timespec ts;
 	struct libinput_event *event;
+	struct udev_input *input = (struct udev_input*)libinput;
 
 	/* Add standard devices */
 	for (int i = 0; i < 10; i++) {
@@ -342,6 +420,10 @@ libinput_udev_assign_seat(struct libinpu
 		post_device_event(device, time, LIBINPUT_EVENT_DEVICE_ADDED,
 		    event);
 	}
+
+	if (udev_input_enable(&input->base) < 0)
+		return -1;
+
 	return 0;
 }
 
@@ -609,6 +691,7 @@ libinput_path_remove_device(struct libin
 {
 	struct libinput *libinput = device->seat->libinput;
 
+	list_remove(&device->link);
 	libinput_remove_source(libinput, device->source);
 	device->source = NULL;
 
