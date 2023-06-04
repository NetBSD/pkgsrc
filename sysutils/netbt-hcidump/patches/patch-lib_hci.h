$NetBSD: patch-lib_hci.h,v 1.2 2023/06/04 09:06:16 plunky Exp $

Not much of the original library is needed.

--- lib/hci.h.orig	2021-10-13 18:38:34.000000000 +0000
+++ lib/hci.h
@@ -27,6 +27,7 @@ extern "C" {
 #define HCI_MAX_EVENT_SIZE	260
 #define HCI_MAX_FRAME_SIZE	(HCI_MAX_AMP_SIZE + 4)
 
+#if 0
 /* HCI dev events */
 #define HCI_DEV_REG	1
 #define HCI_DEV_UNREG	2
@@ -47,12 +48,14 @@ extern "C" {
 #define HCI_I2C		8
 #define HCI_SMD		9
 #define HCI_VIRTIO	10
+#endif
 
 /* HCI controller types */
 #define HCI_PRIMARY	0x00
 #define HCI_AMP		0x01
 #define HCI_BREDR	HCI_PRIMARY
 
+#if 0
 /* HCI device flags */
 enum {
 	HCI_UP,
@@ -100,6 +103,7 @@ enum {
 #define HCIUNBLOCKADDR	_IOW('H', 231, int)
 
 #define HCIINQUIRY	_IOR('H', 240, int)
+#endif
 
 #ifndef __NO_HCI_DEFS
 
@@ -2322,6 +2326,7 @@ typedef struct {
 
 #endif /* _NO_HCI_DEFS */
 
+#if 0
 /* HCI Socket options */
 #define HCI_DATA_DIR	1
 #define HCI_FILTER	2
@@ -2436,6 +2441,12 @@ struct hci_inquiry_req {
 	uint8_t  num_rsp;
 };
 #define IREQ_CACHE_FLUSH 0x0001
+#else
+#define HCI_CMSG_DIR	SCM_HCI_DIRECTION
+#define HCI_CMSG_TSTAMP	SCM_TIMESTAMP
+#define HCI_DEV_NONE	NULL
+#define HCI_DATA_DIR	SO_HCI_DIRECTION
+#endif
 
 #ifdef __cplusplus
 }
