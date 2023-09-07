$NetBSD: patch-lib_mount__bsd.c,v 1.1 2023/09/07 19:38:15 vins Exp $

Use unmount() instead of defining a local function.

--- lib/mount_bsd.c.orig	2019-01-04 13:38:34.000000000 +0000
+++ lib/mount_bsd.c
@@ -10,6 +10,8 @@
 #include "fuse_misc.h"
 #include "fuse_opt.h"
 
+#include <sys/param.h>
+#include <sys/mount.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
 #include <sys/sysctl.h>
@@ -192,56 +194,12 @@ void fuse_unmount_compat22(const char *m
 	free(umount_cmd);
 }
 
-static void do_unmount(char *dev, int fd)
-{
-	char device_path[SPECNAMELEN + 12];
-	const char *argv[4];
-	const char umount_cmd[] = "/sbin/umount";
-	pid_t pid;
-
-	snprintf(device_path, SPECNAMELEN + 12, _PATH_DEV "%s", dev);
-
-	argv[0] = umount_cmd;
-	argv[1] = "-f";
-	argv[2] = device_path;
-	argv[3] = NULL;
-
-	pid = fork();
-
-	if (pid == -1)
-		return;
-
-	if (pid == 0) {
-		close(fd);
-		execvp(umount_cmd, (char **)argv);
-		exit(1);
-	}
-
-	waitpid(pid, NULL, 0);
-}
-
 void fuse_kern_unmount(const char *mountpoint, int fd)
 {
 	char *ep, dev[128];
 	struct stat sbuf;
 
-	(void)mountpoint;
-
-	if (fstat(fd, &sbuf) == -1)
-		goto out;
-
-	devname_r(sbuf.st_rdev, S_IFCHR, dev, 128);
-
-	if (strncmp(dev, "fuse", 4))
-		goto out;
-
-	strtol(dev + 4, &ep, 10);
-	if (*ep != '\0')
-		goto out;
-
-	do_unmount(dev, fd);
-
-out:
+	unmount(mountpoint, MNT_FORCE);
 	close(fd);
 }
 
