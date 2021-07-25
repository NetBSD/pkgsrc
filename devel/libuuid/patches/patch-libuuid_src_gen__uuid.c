$NetBSD: patch-libuuid_src_gen__uuid.c,v 1.2 2021/07/25 04:00:34 dholland Exp $

fcntl is portable, flock is not.
Solaris does not have ifr.ifr_hwaddr.
Rename random_get_bytes to avoid symbol name conflict on Solaris.

--- libuuid/src/gen_uuid.c.orig	2018-06-04 07:57:02.805445789 +0000
+++ libuuid/src/gen_uuid.c
@@ -172,7 +172,7 @@ static int get_node_id(unsigned char *no
 	for (i = 0; i < n; i+= ifreq_size(*ifrp) ) {
 		ifrp = (struct ifreq *)((char *) ifc.ifc_buf+i);
 		strncpy(ifr.ifr_name, ifrp->ifr_name, IFNAMSIZ);
-#ifdef SIOCGIFHWADDR
+#if defined(SIOCGIFHWADDR) && !defined(__sun)
 		if (ioctl(sd, SIOCGIFHWADDR, &ifr) < 0)
 			continue;
 		a = (unsigned char *) &ifr.ifr_hwaddr.sa_data;
@@ -227,12 +227,17 @@ static int get_clock(uint32_t *clock_hig
 	THREAD_LOCAL int		state_fd = -2;
 	THREAD_LOCAL FILE		*state_f;
 	THREAD_LOCAL uint16_t		clock_seq;
+	struct flock			lock;
 	struct timeval			tv;
 	uint64_t			clock_reg;
 	mode_t				save_umask;
 	int				len;
 	int				ret = 0;
 
+	lock.l_whence = SEEK_SET;
+	lock.l_start = 0;
+	lock.l_len = 0;
+
 	if (state_fd == -1)
 		ret = -1;
 
@@ -253,7 +258,8 @@ static int get_clock(uint32_t *clock_hig
 	}
 	if (state_fd >= 0) {
 		rewind(state_f);
-		while (flock(state_fd, LOCK_EX) < 0) {
+		lock.l_type = F_WRLCK;
+		while (fcntl(state_fd, F_SETLKW, &lock) < 0) {
 			if ((errno == EAGAIN) || (errno == EINTR))
 				continue;
 			fclose(state_f);
@@ -278,7 +284,7 @@ static int get_clock(uint32_t *clock_hig
 	}
 
 	if ((last.tv_sec == 0) && (last.tv_usec == 0)) {
-		random_get_bytes(&clock_seq, sizeof(clock_seq));
+		my_random_get_bytes(&clock_seq, sizeof(clock_seq));
 		clock_seq &= 0x3FFF;
 		gettimeofday(&last, NULL);
 		last.tv_sec--;
@@ -325,7 +331,8 @@ try_again:
 			fflush(state_f);
 		}
 		rewind(state_f);
-		flock(state_fd, LOCK_UN);
+		lock.l_type = F_UNLCK;
+		fcntl(state_fd, F_SETLK, &lock);
 	}
 
 	*clock_high = clock_reg >> 32;
@@ -416,7 +423,7 @@ int __uuid_generate_time(uuid_t out, int
 
 	if (!has_init) {
 		if (get_node_id(node_id) <= 0) {
-			random_get_bytes(node_id, 6);
+			my_random_get_bytes(node_id, 6);
 			/*
 			 * Set multicast bit, to prevent conflicts
 			 * with IEEE 802 addresses obtained from
@@ -514,7 +521,7 @@ void __uuid_generate_random(uuid_t out, 
 		n = *num;
 
 	for (i = 0; i < n; i++) {
-		random_get_bytes(buf, sizeof(buf));
+		my_random_get_bytes(buf, sizeof(buf));
 		uuid_unpack(buf, &uu);
 
 		uu.clock_seq = (uu.clock_seq & 0x3FFF) | 0x8000;
