$NetBSD: patch-tools_hcidump.c,v 1.1 2014/12/30 08:39:13 plunky Exp $

changes here, are that netbt stack
 - uses a string for the device address
 - uses sockaddr_bt throughout
 - provides event and packet filters separately

Also, the BSDs provide a socket level TIMESTAMP option

--- tools/hcidump.c.orig	2014-10-05 19:31:20.000000000 +0000
+++ tools/hcidump.c
@@ -135,7 +135,7 @@ static inline int write_n(int fd, char *
 	return t;
 }
 
-static int process_frames(int dev, int sock, int fd, unsigned long flags)
+static int process_frames(char *dev, int sock, int fd, unsigned long flags)
 {
 	struct cmsghdr *cmsg;
 	struct msghdr msg;
@@ -177,7 +177,7 @@ static int process_frames(int dev, int s
 	if (dev == HCI_DEV_NONE)
 		printf("system: ");
 	else
-		printf("device: hci%d ", dev);
+		printf("device: %s ", dev);
 
 	printf("snap_len: %d filter: 0x%lx\n", snap_len, parser.filter);
 
@@ -522,9 +522,9 @@ static int open_file(char *file, int mod
 	return fd;
 }
 
-static int open_socket(int dev, unsigned long flags)
+static int open_socket(char *dev, unsigned long flags)
 {
-	struct sockaddr_hci addr;
+	struct sockaddr_bt addr;
 	struct hci_filter flt;
 	int sk, opt;
 
@@ -542,12 +542,13 @@ static int open_socket(int dev, unsigned
 	}
 
 	opt = 1;
-	if (setsockopt(sk, SOL_HCI, HCI_TIME_STAMP, &opt, sizeof(opt)) < 0) {
+	if (setsockopt(sk, SOL_SOCKET, SO_TIMESTAMP, &opt, sizeof(opt)) < 0) {
 		perror("Can't enable time stamp");
 		return -1;
 	}
 
 	/* Setup filter */
+#if 0
 	hci_filter_clear(&flt);
 	hci_filter_all_ptypes(&flt);
 	hci_filter_all_events(&flt);
@@ -555,13 +556,34 @@ static int open_socket(int dev, unsigned
 		perror("Can't set filter");
 		return -1;
 	}
+#else
+	memset(&flt, 0xff, sizeof(flt));
+	if (setsockopt(sk, BTPROTO_HCI, SO_HCI_EVT_FILTER, &flt, sizeof(flt)) < 0) {
+		perror("Can't set event filter");
+		return -1;
+	}
+
+	if (setsockopt(sk, BTPROTO_HCI, SO_HCI_PKT_FILTER, &flt, sizeof(flt)) < 0) {
+		perror("Can't set packet filter");
+		return -1;
+	}
+#endif
 
 	/* Bind socket to the HCI device */
 	memset(&addr, 0, sizeof(addr));
+#if 0
 	addr.hci_family = AF_BLUETOOTH;
 	addr.hci_dev = dev;
+#else
+	addr.bt_len = sizeof(addr);
+	addr.bt_family = AF_BLUETOOTH;
+	if (dev != HCI_DEV_NONE && !bt_devaddr(dev, &addr.bt_bdaddr)) {
+		perror("device");
+		return -1;
+	}
+#endif
 	if (bind(sk, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
-		printf("Can't attach to device hci%d. %s(%d)\n",
+		printf("Can't attach to device %s. %s(%d)\n",
 					dev, strerror(errno), errno);
 		return -1;
 	}
@@ -672,7 +694,7 @@ int main(int argc, char *argv[])
 {
 	unsigned long flags = 0;
 	unsigned long filter = 0;
-	int device = 0;
+	char *device = HCI_DEV_NONE;
 	int defpsm = 0;
 	int defcompid = DEFAULT_COMPID;
 	int opt, pppdump_fd = -1, audio_fd = -1;
@@ -684,7 +706,7 @@ int main(int argc, char *argv[])
 		switch(opt) {
 		case 'i':
 			if (strcasecmp(optarg, "none") && strcasecmp(optarg, "system"))
-				device = atoi(optarg + 3);
+				device = optarg;
 			else
 				device = HCI_DEV_NONE;
 			break;
