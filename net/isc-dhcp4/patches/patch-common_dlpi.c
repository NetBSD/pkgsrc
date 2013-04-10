$NetBSD: patch-common_dlpi.c,v 1.1 2013/04/10 11:31:27 fhajny Exp $

Add support for Crossbow style NICs (SunOS).

--- common/dlpi.c.orig	2013-01-03 00:02:24.000000000 +0000
+++ common/dlpi.c
@@ -131,6 +131,7 @@ static int strioctl (int fd, int cmd, in
 #define DLPI_MAXDLBUF		8192	/* Buffer size */
 #define DLPI_MAXDLADDR		1024	/* Max address size */
 #define DLPI_DEVDIR		"/dev/"	/* Device directory */
+#define DLPI_DEVDIR_NEW		"/dev/net/"	/* Crossbow Device directory */
 
 static int dlpiopen(const char *ifname);
 static int dlpiunit (char *ifname);
@@ -775,14 +776,26 @@ static int dlpiunit (ifname)
  */
 static int
 dlpiopen(const char *ifname) {
-	char devname [50];
+	char devname [MAXPATHLEN];
 	char *dp;
 	const char *cp, *ep;
+	int fd;
 	
 	if (!ifname) {
 		return -1;
 	}
 	
+	/* Try Crossbow Device Path */
+	if (ifname[0] == '/') {
+		fd = open (ifname, O_RDWR, 0);
+	} else {
+		snprintf(devname, MAXPATHLEN, "%s%s", DLPI_DEVDIR_NEW, ifname);
+		fd = open (devname, O_RDWR, 0);
+	}
+	if (fd != -1 || errno != ENOENT) {
+		return fd;
+	}
+
 	/* Open a DLPI device */
 	if (*ifname == '/') {
 		dp = devname;
