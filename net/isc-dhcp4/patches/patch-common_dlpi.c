$NetBSD: patch-common_dlpi.c,v 1.3 2016/03/30 15:55:44 taca Exp $

Add support for Crossbow style NICs (SunOS).

--- common/dlpi.c.orig	2016-03-22 13:16:51.000000000 +0000
+++ common/dlpi.c
@@ -778,14 +778,26 @@ static int dlpiunit (ifname)
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
