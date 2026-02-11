$NetBSD: patch-spectro_hidio.c,v 1.3 2026/02/11 02:41:15 jakllsch Exp $

Recognize NetBSD.

--- spectro/hidio.c.orig	2026-02-09 22:25:25.000000000 +0000
+++ spectro/hidio.c
@@ -92,6 +92,10 @@
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__)
 #include <sys/types.h> 
 #include <usbhid.h> 
+#elif defined(__NetBSD__)
+#include <glob.h>
+#include <dev/usb/usb.h>
+#include <usbhid.h> 
 #else	/* assume Linux */ 
 # include <asm/types.h>
 # include <linux/hiddev.h>
@@ -437,11 +441,54 @@ int hid_get_paths(icompaths *p) {
 #endif /* UNIX_APPLE */
 
 #if defined(UNIX_X11)
+#if defined(__NetBSD__)
+	{
+		int i;
+		int fd;
+		glob_t g;
+		const char *uhid_glob = "/dev/uhid[0-9]*";
+		struct usb_device_info udi;
+		devType itype;
+
+		if (glob(uhid_glob, GLOB_NOSORT, NULL, &g) != 0) {
+			return ICOM_SYS;
+		}
+
+		for (i = 0; i < g.gl_pathc; i++) {
+			struct hid_idevice *hidd;
+			if ((fd = open(g.gl_pathv[i], O_RDONLY)) < 0)
+				continue;
+
+			if (ioctl(fd, USB_GET_DEVICEINFO, &udi) < 0) {
+                                a1logd(p->log, 6, "hid_get_paths: USB_GET_DEVICEINFO failed\n");
+				close(fd);
+				continue;
+			}
+			close(fd);
 
+			/* Do a preliminary match */
+                        if ((itype = inst_usb_match(udi.udi_vendorNo, udi.udi_productNo, 0)) == instUnknown) {
+                                a1logd(p->log, 6, "hid_get_paths: instrument not reconized\n");
+                                continue;
+                        }
+			if ((hidd = (struct hid_idevice *) calloc(sizeof(struct hid_idevice), 1)) == NULL) {
+		        	a1loge(p->log, 6, "hid_get_paths() calloc failed!\n");
+				return ICOM_SYS;
+			}
+			if ((hidd->dpath = strdup(g.gl_pathv[i])) == NULL) {
+		        	a1loge(p->log, 6, "hid_get_paths() strdup failed!\n");
+				return ICOM_SYS;
+			}
+			p->add_hid(p, hidd->dpath, udi.udi_vendorNo, udi.udi_productNo, 0, hidd, itype);
+		}
+		
+		globfree(&g);
+	}
+#elif defined NEVER
 	/* This is how we'd go about adding HID support for Linux, IF it */
 	/* was actually capable of communicating application composed reports - */
 	/* which it is not, so HID seems pretty busted on Linux.. */
-#ifdef NEVER
+
 	/* We need to scan for /dev/hiddev* or /dev/usb/hiddev* device names, */
 	/* and then read their vid & pid */
 	{
@@ -723,6 +770,24 @@ char **pnames			/* List of process names
 #endif	/* MAC_OS_X_VERSION_MIN_REQUIRED < 1060 */
 #endif /* UNIX_APPLE */
 
+#if defined(UNIX_X11) && defined(__NetBSD__)
+		static int hid_inited;
+		if (!hid_inited) {
+			hid_init(NULL);
+			hid_inited = 1;
+		}
+		p->hidd->fd = open(p->hidd->dpath, O_RDWR);
+		if (p->hidd->fd < 0)
+			return ICOM_SYS;
+		report_desc_t rd = hid_get_report_desc(p->hidd->fd);
+		p->hidd->rchunk = hid_report_size(rd, hid_input, 0);
+		p->hidd->wchunk = hid_report_size(rd, hid_output, 0);
+		hid_dispose_report_desc(rd);
+
+		if (p->hidd->rchunk <= 0 || p->hidd->wchunk <= 0)
+			return ICOM_SYS;
+#endif
+
 		p->is_open = 1;
 		a1logd(p->log, 8, "hid_open_port: HID port is now open\n");
 	}
@@ -780,6 +845,12 @@ void hid_close_port(icoms *p) {
 #endif	/* MAC_OS_X_VERSION_MIN_REQUIRED < 1060 */
 #endif /* UNIX_APPLE */
 
+#if defined(UNIX_X11)
+#if defined(__NetBSD__)
+		close(p->hidd->fd);
+#endif
+#endif
+
 		p->is_open = 0;
 		a1logd(p->log, 8, "hid_close_port: has been released and closed\n");
 	}
@@ -988,6 +1059,19 @@ printf("~1 IOHIDDeviceGet returned 0x%x\
 #endif	/* MAC_OS_X_VERSION_MIN_REQUIRED < 1060 */
 #endif /* UNIX_APPLE */
 
+#if defined(UNIX_X11) && defined(__NetBSD__)
+	if (bsize % p->hidd->rchunk != 0)
+		return ICOM_SYS; /* XXX right error code? */
+	for (size_t i = 0; i < bsize; i += p->hidd->rchunk) {
+		ssize_t ret;
+		ret = read(p->hidd->fd, &rbuf[i], p->hidd->rchunk);
+		if (ret < 0)
+			return ICOM_SYS; /* XXX right error code? */
+		else
+			bread += ret;
+	}
+#endif
+
 	if (breadp != NULL)
 		*breadp = bread;
 
@@ -1138,6 +1222,19 @@ printf("~1 IOHIDDeviceSetReportWithCallb
 #endif	/* MAC_OS_X_VERSION_MIN_REQUIRED < 1060 */
 #endif /* UNIX_APPLE */
 
+#if defined(UNIX_X11) && defined(__NetBSD__)
+	if (bsize % p->hidd->wchunk != 0)
+		return ICOM_SYS; /* XXX right error code? */
+	for (size_t i = 0; i < bsize; i += p->hidd->wchunk) {
+		ssize_t ret;
+		ret = write(p->hidd->fd, &wbuf[i], p->hidd->wchunk);
+		if (ret < 0)
+			return ICOM_SYS; /* XXX right error code? */
+		else
+			bwritten + ret;
+	}
+#endif
+
 	if (bwrittenp != NULL)
 		*bwrittenp = bwritten;
 
@@ -1208,6 +1305,12 @@ int hid_copy_hid_idevice(icoms *d, icomp
 #endif	/* MAC_OS_X_VERSION_MIN_REQUIRED < 1060 */
 #endif	/* UNIX_APPLE */
 #if defined (UNIX_X11)
+# if defined (__NetBSD__)
+	if ((d->hidd->dpath = strdup(s->hidd->dpath)) == NULL) {
+		a1loge(d->log, ICOM_SYS, "hid_copy_hid_idevice: malloc\n");
+		return ICOM_SYS;
+	}
+# endif
 #endif
 	if (s->hidd->SerialNumber != NULL 
 	 && (d->hidd->SerialNumber = strdup(s->hidd->SerialNumber)) == NULL) {
@@ -1237,6 +1340,10 @@ void hid_del_hid_idevice(struct hid_idev
 #endif	/* MAC_OS_X_VERSION_MIN_REQUIRED < 1060 */
 #endif	/* UNIX_APPLE */
 #if defined (UNIX_X11)
+# if defined (__NetBSD__)
+	if (hidd->dpath != NULL)
+		free(hidd->dpath);
+# endif
 #endif
 	if (hidd->SerialNumber != NULL)
 		free(hidd->SerialNumber);
