$NetBSD: patch-src_control_control__hw.c,v 1.2 2026/01/08 09:16:32 wiz Exp $

--- src/control/control_hw.c.orig	2025-12-19 10:31:58.000000000 +0000
+++ src/control/control_hw.c
@@ -87,10 +87,11 @@ static int snd_ctl_hw_async(snd_ctl_t *ctl, int sig, p
 
 static int snd_ctl_hw_async(snd_ctl_t *ctl, int sig, pid_t pid)
 {
-	long flags;
 	snd_ctl_hw_t *hw = ctl->private_data;
 	int fd = hw->fd;
 
+#ifndef __sun
+	long flags;
 	if ((flags = fcntl(fd, F_GETFL)) < 0) {
 		snd_errornum(CONTROL, "F_GETFL failed");
 		return -errno;
@@ -103,12 +104,15 @@ static int snd_ctl_hw_async(snd_ctl_t *ctl, int sig, p
 		snd_errornum(CONTROL, "F_SETFL for O_ASYNC failed");
 		return -errno;
 	}
+#endif
 	if (sig < 0)
 		return 0;
+#ifndef __sun
 	if (fcntl(fd, F_SETSIG, (long)sig) < 0) {
 		snd_errornum(CONTROL, "F_SETSIG failed");
 		return -errno;
 	}
+#endif
 	if (fcntl(fd, F_SETOWN, (long)pid) < 0) {
 		snd_errornum(CONTROL, "F_SETOWN failed");
 		return -errno;
@@ -448,8 +452,10 @@ int snd_ctl_hw_open(snd_ctl_t **handle, const char *na
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
