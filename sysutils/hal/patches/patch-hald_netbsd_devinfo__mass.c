$NetBSD: patch-hald_netbsd_devinfo__mass.c,v 1.1 2017/01/17 15:25:27 wiz Exp $

Include sys/stat.h for struct stat.

--- hald/netbsd/devinfo_mass.c.orig	2017-01-17 15:21:27.139265878 +0000
+++ hald/netbsd/devinfo_mass.c
@@ -35,6 +35,7 @@
 #include <sys/ioctl.h>
 #include <sys/scsiio.h>
 #include <dev/scsipi/scsipi_all.h>
+#include <sys/stat.h>
 #include <ctype.h>
 #include <errno.h>
 #include <fcntl.h>
