$NetBSD: patch-libuuid_src_gen__uuid.c,v 1.3 2024/12/28 14:10:24 wiz Exp $

Solaris does not have ifr.ifr_hwaddr.
fcntl is portable, flock is not.

--- libuuid/src/gen_uuid.c.orig	2024-07-04 07:54:41.230242078 +0000
+++ libuuid/src/gen_uuid.c
@@ -167,7 +167,7 @@ static int get_node_id(unsigned char *no
 	for (i = 0; i < n; i+= ifreq_size(*ifrp) ) {
 		ifrp = (struct ifreq *)((char *) ifc.ifc_buf+i);
 		strncpy(ifr.ifr_name, ifrp->ifr_name, IFNAMSIZ);
-#ifdef SIOCGIFHWADDR
+#if defined(SIOCGIFHWADDR) && !defined(__sun)
 		if (ioctl(sd, SIOCGIFHWADDR, &ifr) < 0)
 			continue;
 		a = (unsigned char *) &ifr.ifr_hwaddr.sa_data;
@@ -246,16 +246,22 @@ static int get_clock(uint32_t *clock_hig
 	THREAD_LOCAL int		state_fd = STATE_FD_INIT;
 	THREAD_LOCAL FILE		*state_f;
 	THREAD_LOCAL uint16_t		clock_seq;
+	struct flock			lock;
 	struct timeval			tv;
 	uint64_t			clock_reg;
 	int				ret = 0;
 
+	lock.l_whence = SEEK_SET;
+	lock.l_start = 0;
+	lock.l_len = 0;
+
 	if (state_fd == STATE_FD_INIT)
 		state_fd = state_fd_init(LIBUUID_CLOCK_FILE, &state_f);
 
 	if (state_fd >= 0) {
 		rewind(state_f);
-		while (flock(state_fd, LOCK_EX) < 0) {
+		lock.l_type = F_WRLCK;
+		while (fcntl(state_fd, F_SETLKW, &lock) < 0) {
 			if ((errno == EAGAIN) || (errno == EINTR))
 				continue;
 			fclose(state_f);
@@ -334,7 +340,8 @@ try_again:
 			      clock_seq, (long)last.tv_sec, (long)last.tv_usec, adjustment);
 		fflush(state_f);
 		rewind(state_f);
-		flock(state_fd, LOCK_UN);
+		lock.l_type = F_UNLCK;
+		fcntl(state_fd, F_SETLK, &lock);
 	}
 
 	*clock_high = clock_reg >> 32;
