$NetBSD: patch-common_dlpi.c,v 1.4 2022/03/13 15:24:38 taca Exp $

Add support for Crossbow style NICs (SunOS).

--- common/dlpi.c.orig	2022-03-08 09:26:03.000000000 +0000
+++ common/dlpi.c
@@ -782,14 +782,26 @@ static int dlpiunit (ifname)
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
+		snprintf(devname, MAXPATHLEN, "%s%s", DLPI_DEVDIR, ifname);
+		fd = open (devname, O_RDWR, 0);
+	}
+	if (fd != -1 || errno != ENOENT) {
+		return fd;
+	}
+
 	/* Open a DLPI device */
 	if (*ifname == '/') {
 		dp = devname;
