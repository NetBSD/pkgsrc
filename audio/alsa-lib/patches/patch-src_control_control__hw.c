$NetBSD: patch-src_control_control__hw.c,v 1.1 2012/02/15 19:43:51 hans Exp $

--- src/control/control_hw.c.orig	2009-12-16 16:18:51.000000000 +0100
+++ src/control/control_hw.c	2012-01-15 01:48:06.780384687 +0100
@@ -80,10 +80,11 @@ static int snd_ctl_hw_nonblock(snd_ctl_t
 
 static int snd_ctl_hw_async(snd_ctl_t *ctl, int sig, pid_t pid)
 {
-	long flags;
 	snd_ctl_hw_t *hw = ctl->private_data;
 	int fd = hw->fd;
 
+#ifndef __sun
+	long flags;
 	if ((flags = fcntl(fd, F_GETFL)) < 0) {
 		SYSERR("F_GETFL failed");
 		return -errno;
@@ -96,12 +97,15 @@ static int snd_ctl_hw_async(snd_ctl_t *c
 		SYSERR("F_SETFL for O_ASYNC failed");
 		return -errno;
 	}
+#endif
 	if (sig < 0)
 		return 0;
+#ifndef __sun
 	if (fcntl(fd, F_SETSIG, (long)sig) < 0) {
 		SYSERR("F_SETSIG failed");
 		return -errno;
 	}
+#endif
 	if (fcntl(fd, F_SETOWN, (long)pid) < 0) {
 		SYSERR("F_SETOWN failed");
 		return -errno;
@@ -383,8 +387,10 @@ int snd_ctl_hw_open(snd_ctl_t **handle, 
 		fmode = O_RDWR;
 	if (mode & SND_CTL_NONBLOCK)
 		fmode |= O_NONBLOCK;
+#ifndef __sun
 	if (mode & SND_CTL_ASYNC)
 		fmode |= O_ASYNC;
+#endif
 	fd = snd_open_device(filename, fmode);
 	if (fd < 0) {
 		snd_card_load(card);
