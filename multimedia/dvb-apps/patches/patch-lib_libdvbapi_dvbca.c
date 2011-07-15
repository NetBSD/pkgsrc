$NetBSD: patch-lib_libdvbapi_dvbca.c,v 1.1 2011/07/15 22:59:20 jmcneill Exp $

--- lib/libdvbapi/dvbca.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libdvbapi/dvbca.c
@@ -27,7 +27,11 @@
 #include <unistd.h>
 #include <ctype.h>
 #include <errno.h>
+#ifdef __NetBSD__
+#include <dev/dtv/dtvio.h>
+#else
 #include <linux/dvb/ca.h>
+#endif
 #include "dvbca.h"
 
 
@@ -48,11 +52,16 @@ int dvbca_open(int adapter, int cadevice
 
 int dvbca_reset(int fd, uint8_t slot)
 {
+#ifdef CA_RESET
 	return ioctl(fd, CA_RESET, (1 << slot));
+#else
+	return -1;
+#endif
 }
 
 int dvbca_get_interface_type(int fd, uint8_t slot)
 {
+#ifdef CA_GET_SLOT_INFO
 	ca_slot_info_t info;
 
 	info.num = slot;
@@ -63,12 +72,14 @@ int dvbca_get_interface_type(int fd, uin
 		return DVBCA_INTERFACE_LINK;
 	if (info.type & CA_CI)
 		return DVBCA_INTERFACE_HLCI;
+#endif
 
 	return -1;
 }
 
 int dvbca_get_cam_state(int fd, uint8_t slot)
 {
+#ifdef CA_GET_SLOT_INFO
 	ca_slot_info_t info;
 
 	info.num = slot;
@@ -81,6 +92,7 @@ int dvbca_get_cam_state(int fd, uint8_t 
 		return DVBCA_CAMSTATE_READY;
 	if (info.flags & CA_CI_MODULE_PRESENT)
 		return DVBCA_CAMSTATE_INITIALISING;
+#endif
 
 	return -1;
 }
@@ -123,6 +135,7 @@ int dvbca_link_read(int fd, uint8_t *slo
 
 int dvbca_hlci_write(int fd, uint8_t *data, uint16_t data_length)
 {
+#ifdef CA_SEND_MSG
 	struct ca_msg msg;
 
 	if (data_length > 256) {
@@ -134,11 +147,15 @@ int dvbca_hlci_write(int fd, uint8_t *da
 	memcpy(msg.msg, data, data_length);
 
 	return ioctl(fd, CA_SEND_MSG, &msg);
+#else
+	return -1;
+#endif
 }
 
 int dvbca_hlci_read(int fd, uint32_t app_tag, uint8_t *data,
 		    uint16_t data_length)
 {
+#ifdef CA_GET_MSG
 	struct ca_msg msg;
 
 	if (data_length > 256) {
@@ -156,4 +173,7 @@ int dvbca_hlci_read(int fd, uint32_t app
 	if (msg.length > data_length) msg.length = data_length;
 	memcpy(data, msg.msg, msg.length);
 	return msg.length;
+#else
+	return -1;
+#endif
 }
