$NetBSD: patch-include_ntp__request.h,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- include/ntp_request.h.orig	2020-03-03 23:41:29.000000000 +0000
+++ include/ntp_request.h
@@ -129,6 +129,25 @@ typedef union req_data_u_tag {
 } req_data_u;				/* struct conf_peer must fit */
 
 /*
+ * Structure for carrying system flags.
+ */
+struct conf_sys_flags {
+	u_int32 flags;
+};
+
+/*
+ * System flags we can set/clear
+ */
+#define	SYS_FLAG_BCLIENT	0x01
+#define	SYS_FLAG_PPS		0x02
+#define SYS_FLAG_NTP		0x04
+#define SYS_FLAG_KERNEL		0x08
+#define SYS_FLAG_MONITOR	0x10
+#define SYS_FLAG_FILEGEN	0x20
+#define SYS_FLAG_AUTH		0x40
+#define SYS_FLAG_CAL		0x80
+
+/*
  * A request packet.  These are almost a fixed length.
  */
 struct req_pkt {
@@ -226,8 +245,8 @@ struct resp_pkt {
 
 #define	INFO_ERR(err_nitems)	((u_short)((ntohs(err_nitems)>>12)&0xf))
 #define	INFO_NITEMS(err_nitems)	((u_short)(ntohs(err_nitems)&0xfff))
-#define	ERR_NITEMS(err, nitems)	(htons((u_short)((((u_short)(err)<<12)&0xf000)\
-				|((u_short)(nitems)&0xfff))))
+#define _ERR_EN(err)		((u_short)(((err)&0xf)<<12))
+#define	ERR_NITEMS(err, nitems)	((u_short)htons(_ERR_EN(err)|(nitems&0xfff)))
 
 #define	INFO_MBZ(mbz_itemsize)	((ntohs(mbz_itemsize)>>12)&0xf)
 #define	INFO_ITEMSIZE(mbz_itemsize)	((u_short)(ntohs(mbz_itemsize)&0xfff))
@@ -629,25 +648,6 @@ struct conf_unpeer {
 };
 
 /*
- * Structure for carrying system flags.
- */
-struct conf_sys_flags {
-	u_int32 flags;
-};
-
-/*
- * System flags we can set/clear
- */
-#define	SYS_FLAG_BCLIENT	0x01
-#define	SYS_FLAG_PPS		0x02
-#define SYS_FLAG_NTP		0x04
-#define SYS_FLAG_KERNEL		0x08
-#define SYS_FLAG_MONITOR	0x10
-#define SYS_FLAG_FILEGEN	0x20
-#define SYS_FLAG_AUTH		0x40
-#define SYS_FLAG_CAL		0x80
-
-/*
  * Structure used for returning restrict entries
  */
 struct info_restrict {
