$NetBSD: patch-spectro_hidio.c,v 1.1 2023/11/17 17:37:48 jakllsch Exp $

Recognize NetBSD.

--- spectro/hidio.c.orig	2023-10-23 00:56:17.000000000 +0000
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
@@ -432,11 +436,54 @@ int hid_get_paths(icompaths *p) {
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
@@ -652,6 +699,24 @@ char **pnames			/* List of process names
 #endif	/* __MAC_OS_X_VERSION_MAX_ALLOWED < 1060 */
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
@@ -709,6 +774,10 @@ void hid_close_port(icoms *p) {
 #endif	/* __MAC_OS_X_VERSION_MAX_ALLOWED < 1060 */
 #endif /* UNIX_APPLE */
 
+#if defined(UNIX_X11) && defined(__NetBSD__)
+		close(p->hidd->fd);
+#endif
+
 		p->is_open = 0;
 		a1logd(p->log, 8, "hid_close_port: has been released and closed\n");
 	}
@@ -907,6 +976,19 @@ printf("~1 IOHIDDeviceGet returned 0x%x\
 #endif	/* __MAC_OS_X_VERSION_MAX_ALLOWED < 1060 */
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
 
@@ -1047,6 +1129,19 @@ printf("~1 IOHIDDeviceSetReportWithCallb
 #endif	/* __MAC_OS_X_VERSION_MAX_ALLOWED < 1060 */
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
 
@@ -1117,6 +1212,10 @@ int hid_copy_hid_idevice(icoms *d, icomp
 #endif	/* __MAC_OS_X_VERSION_MAX_ALLOWED < 1060 */
 #endif	/* UNIX_APPLE */
 #if defined (UNIX_X11)
+	if ((d->hidd->dpath = strdup(s->hidd->dpath)) == NULL) {
+		a1loge(d->log, ICOM_SYS, "hid_copy_hid_idevice: malloc\n");
+		return ICOM_SYS;
+	}
 #endif
 	return ICOM_OK;
 }
@@ -1140,6 +1239,8 @@ void hid_del_hid_idevice(struct hid_idev
 #endif	/* __MAC_OS_X_VERSION_MAX_ALLOWED < 1060 */
 #endif	/* UNIX_APPLE */
 #if defined (UNIX_X11)
+	if (hidd->dpath != NULL)
+		free(hidd->dpath);
 #endif
 	free(hidd);
 }
