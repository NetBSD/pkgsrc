$NetBSD: patch-plugins_check_ide_smart.c,v 1.1 2013/01/19 09:59:12 manu Exp $

NetBSD support for SMART checks

--- plugins/check_ide_smart.c.orig	2012-12-27 09:37:31.000000000 +0100
+++ plugins/check_ide_smart.c	2012-12-27 09:37:31.000000000 +0100
@@ -47,6 +47,27 @@
 #include <sys/ioctl.h>
 #include <fcntl.h>
+#ifdef linux
 #include <linux/hdreg.h>
 #include <linux/types.h>
+
+#define OPEN_MODE O_RDONLY
+#endif /* linux */
+#ifdef __NetBSD__
+#include <sys/device.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/videoio.h> /* for __u8 and friends */
+#include <sys/scsiio.h>
+#include <sys/ataio.h>
+#include <dev/ata/atareg.h>
+#include <dev/ic/wdcreg.h>
+
+#define SMART_ENABLE WDSM_ENABLE_OPS
+#define SMART_DISABLE WDSM_DISABLE_OPS
+#define SMART_IMMEDIATE_OFFLINE WDSM_EXEC_OFFL_IMM
+#define SMART_AUTO_OFFLINE 0xdb /* undefined in NetBSD headers */
+
+#define OPEN_MODE O_RDWR
+#endif /* __NetBSD__ */
 #include <errno.h>
 	
@@ -224,5 +245,5 @@
 	}
 
-	fd = open (device, O_RDONLY);
+	fd = open (device, OPEN_MODE);
 
 	if (fd < 0) {
@@ -285,4 +306,5 @@
 smart_read_values (int fd, values_t * values) 
 {
+#ifdef linux
 	int e;
 	__u8 args[4 + 512];
@@ -297,4 +319,33 @@
 	}
 	memcpy (values, args + 4, 512);
+#endif /* linux */
+#ifdef __NetBSD__
+	struct atareq req;
+	unsigned char inbuf[DEV_BSIZE];
+
+	memset(&req, 0, sizeof(req));
+	req.timeout = 1000;
+	memset(&inbuf, 0, sizeof(inbuf));
+
+	req.flags = ATACMD_READ;
+	req.features = WDSM_RD_DATA;
+	req.command = WDCC_SMART;
+ 	req.databuf = (char *)inbuf;
+ 	req.datalen = sizeof(inbuf);
+	req.cylinder = WDSMART_CYL;
+
+	if (ioctl(fd, ATAIOCCOMMAND, &req) == 0) {
+		if (req.retsts != ATACMD_OK)
+			errno = ENODEV;
+	}
+
+	if (errno != 0) {
+		int e = errno;
+		printf (_("CRITICAL - SMART_READ_VALUES: %s\n"), strerror (errno));
+		return e;
+	}
+	
+	(void)memcpy(values, inbuf, 512);
+#endif /* __NetBSD__ */
 	return 0;
 }
@@ -440,4 +491,5 @@
 {
 	int e = 0;
+#ifdef linux
 	__u8 args[4];
 	args[0] = WIN_SMART;
@@ -451,4 +503,29 @@
 		}
 	}
+#endif /* linux */
+#ifdef __NetBSD__
+	struct atareq req;
+
+	memset(&req, 0, sizeof(req));
+	req.timeout = 1000;
+	req.flags = ATACMD_READREG;
+	req.features = smart_command[command].value;
+	req.command = WDCC_SMART;
+	req.cylinder = WDSMART_CYL;
+	req.sec_count = val0;
+
+	if (ioctl(fd, ATAIOCCOMMAND, &req) == 0) {
+		if (req.retsts != ATACMD_OK)
+			errno = ENODEV;
+		if (req.cylinder != WDSMART_CYL)
+			errno = ENODEV;
+	}
+
+	if (errno != 0) {
+		e = errno;
+		printf (_("CRITICAL - %s: %s\n"), smart_command[command].text, strerror (errno));
+		return e;
+	}
+#endif /* __NetBSD__ */
 	return e;
 }
@@ -459,4 +536,5 @@
 smart_read_thresholds (int fd, thresholds_t * thresholds) 
 {
+#ifdef linux
 	int e;
 	__u8 args[4 + 512];
@@ -471,4 +549,33 @@
 	}
 	memcpy (thresholds, args + 4, 512);
+#endif /* linux */
+#ifdef __NetBSD__
+	struct atareq req;
+	unsigned char inbuf[DEV_BSIZE];
+
+	memset(&req, 0, sizeof(req));
+	req.timeout = 1000;
+	memset(&inbuf, 0, sizeof(inbuf));
+
+	req.flags = ATACMD_READ;
+	req.features = WDSM_RD_THRESHOLDS;
+	req.command = WDCC_SMART;
+ 	req.databuf = (char *)inbuf;
+ 	req.datalen = sizeof(inbuf);
+	req.cylinder = WDSMART_CYL;
+
+	if (ioctl(fd, ATAIOCCOMMAND, &req) == 0) {
+		if (req.retsts != ATACMD_OK)
+			errno = ENODEV;
+	}
+
+	if (errno != 0) {
+		int e = errno;
+		printf (_("CRITICAL - SMART_READ_THRESHOLDS: %s\n"), strerror (errno));
+		return e;
+	}
+	
+	(void)memcpy(thresholds, inbuf, 512);
+#endif /* __NetBSD__ */
 	return 0;
 }
