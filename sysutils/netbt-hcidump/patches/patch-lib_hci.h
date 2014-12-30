$NetBSD: patch-lib_hci.h,v 1.1 2014/12/30 08:39:13 plunky Exp $

Not much of the original library is needed.

--- lib/hci.h.orig	2014-12-26 17:54:42.000000000 +0000
+++ lib/hci.h
@@ -39,6 +39,7 @@ extern "C" {
 #define HCI_MAX_EVENT_SIZE	260
 #define HCI_MAX_FRAME_SIZE	(HCI_MAX_ACL_SIZE + 4)
 
+#if 0
 /* HCI dev events */
 #define HCI_DEV_REG	1
 #define HCI_DEV_UNREG	2
@@ -55,11 +56,13 @@ extern "C" {
 #define HCI_RS232	4
 #define HCI_PCI		5
 #define HCI_SDIO	6
+#endif
 
 /* HCI controller types */
 #define HCI_BREDR	0x00
 #define HCI_AMP		0x01
 
+#if 0
 /* HCI device flags */
 enum {
 	HCI_UP,
@@ -107,6 +110,7 @@ enum {
 #define HCIUNBLOCKADDR	_IOW('H', 231, int)
 
 #define HCIINQUIRY	_IOR('H', 240, int)
+#endif
 
 #ifndef __NO_HCI_DEFS
 
@@ -2328,6 +2332,7 @@ typedef struct {
 
 #endif /* _NO_HCI_DEFS */
 
+#if 0
 /* HCI Socket options */
 #define HCI_DATA_DIR	1
 #define HCI_FILTER	2
@@ -2441,6 +2446,12 @@ struct hci_inquiry_req {
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
