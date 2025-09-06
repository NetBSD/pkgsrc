$NetBSD: patch-src_socket__wrapper.c,v 1.1 2025/09/06 18:29:02 riastradh Exp $

1. Handle NetBSD's different prototypes for recvmsg/sendmsg.  (PR
   lib/59633: recvmmsg prototype is incompatible with FreeBSD and
   Linux)

2. Handle the symbol rename __socket30 in NetBSD.

3. PIPE_BUF=4096 is a Linuxism; the BSDs have PIPE_BUF=512.  Maybe
   this isn't reliable with PIPE_BUF=512, but let's try anyway.

--- src/socket_wrapper.c.orig	2025-05-06 08:09:04.000000000 +0000
+++ src/socket_wrapper.c
@@ -562,6 +562,9 @@ typedef int (*__libc_recvfrom)(int sockf
 			     socklen_t *addrlen);
 typedef int (*__libc_recvmsg)(int sockfd, const struct msghdr *msg, int flags);
 #ifdef HAVE_RECVMMSG
+#ifdef __NetBSD__
+typedef int (*__libc_recvmmsg)(int sockfd, struct mmsghdr *msgvec, unsigned int vlen, unsigned int flags, struct timespec *timeout);
+#else
 #if defined(HAVE_RECVMMSG_SSIZE_T_CONST_TIMEOUT)
 /* FreeBSD */
 typedef ssize_t (*__libc_recvmmsg)(int sockfd, struct mmsghdr *msgvec, size_t vlen, int flags, const struct timespec *timeout);
@@ -572,10 +575,14 @@ typedef int (*__libc_recvmmsg)(int sockf
 /* Linux glibc >= 2.21 */
 typedef int (*__libc_recvmmsg)(int sockfd, struct mmsghdr *msgvec, unsigned int vlen, int flags, struct timespec *timeout);
 #endif
+#endif
 #endif /* HAVE_RECVMMSG */
 typedef int (*__libc_send)(int sockfd, const void *buf, size_t len, int flags);
 typedef int (*__libc_sendmsg)(int sockfd, const struct msghdr *msg, int flags);
 #ifdef HAVE_SENDMMSG
+#ifdef __NetBSD__
+typedef int (*__libc_sendmmsg)(int sockfd, struct mmsghdr *msgvec, unsigned int vlen, unsigned int flags);
+#else
 #if defined(HAVE_SENDMMSG_SSIZE_T)
 /* FreeBSD */
 typedef ssize_t (*__libc_sendmmsg)(int sockfd, struct mmsghdr *msgvec, size_t vlen, int flags);
@@ -583,6 +590,7 @@ typedef ssize_t (*__libc_sendmmsg)(int s
 /* Linux */
 typedef int (*__libc_sendmmsg)(int sockfd, struct mmsghdr *msgvec, unsigned int vlen, int flags);
 #endif
+#endif
 #endif /* HAVE_SENDMMSG */
 typedef int (*__libc_sendto)(int sockfd,
 			   const void *buf,
@@ -829,6 +837,27 @@ static void *swrap_load_lib_handle(enum 
 	return handle;
 }
 
+#ifdef __NetBSD__
+static void *
+wrap_dlsym(void *handle, const char *symbol)
+{
+	static const struct {
+		const char *public, *internal;
+	} renames[] = {
+		{ "socket", "__socket30" },
+	};
+	size_t i;
+
+	for (i = 0; i < sizeof(renames)/sizeof(renames[0]); i++) {
+		if (strcmp(symbol, renames[i].public) == 0)
+			return dlsym(handle, renames[i].internal);
+	}
+	return dlsym(handle, symbol);
+}
+#else
+#define	wrap_dlsym	dlsym
+#endif
+
 static void *_swrap_bind_symbol(enum swrap_lib lib, const char *fn_name)
 {
 	void *handle;
@@ -836,7 +865,7 @@ static void *_swrap_bind_symbol(enum swr
 
 	handle = swrap_load_lib_handle(lib);
 
-	func = dlsym(handle, fn_name);
+	func = wrap_dlsym(handle, fn_name);
 	if (func == NULL) {
 		SWRAP_LOG(SWRAP_LOG_ERROR,
 			  "Failed to find %s: %s",
@@ -898,7 +927,7 @@ static void _swrap_mutex_unlock(pthread_
 
 #define swrap_bind_symbol_rtld_default_optional(sym_name) do { \
 	swrap.rtld_default.symbols._rtld_default_##sym_name.obj = \
-		dlsym(RTLD_DEFAULT, #sym_name); \
+		wrap_dlsym(RTLD_DEFAULT, #sym_name); \
 } while(0);
 
 static void swrap_bind_symbol_all(void);
@@ -1266,6 +1295,9 @@ static int libc_recvmsg(int sockfd, stru
 }
 
 #ifdef HAVE_RECVMMSG
+#ifdef __NetBSD__
+static int libc_recvmmsg(int sockfd, struct mmsghdr *msgvec, unsigned int vlen, unsigned int flags, struct timespec *timeout)
+#else
 #if defined(HAVE_RECVMMSG_SSIZE_T_CONST_TIMEOUT)
 /* FreeBSD */
 static ssize_t libc_recvmmsg(int sockfd, struct mmsghdr *msgvec, size_t vlen, int flags, const struct timespec *timeout)
@@ -1276,6 +1308,7 @@ static int libc_recvmmsg(int sockfd, str
 /* Linux glibc >= 2.21 */
 static int libc_recvmmsg(int sockfd, struct mmsghdr *msgvec, unsigned int vlen, int flags, struct timespec *timeout)
 #endif
+#endif
 {
 	swrap_bind_symbol_all();
 
@@ -1298,6 +1331,9 @@ static int libc_sendmsg(int sockfd, cons
 }
 
 #ifdef HAVE_SENDMMSG
+#ifdef __NetBSD__
+static int libc_sendmmsg(int sockfd, struct mmsghdr *msgvec, unsigned int vlen, unsigned int flags)
+#else
 #if defined(HAVE_SENDMMSG_SSIZE_T)
 /* FreeBSD */
 static ssize_t libc_sendmmsg(int sockfd, struct mmsghdr *msgvec, size_t vlen, int flags)
@@ -1305,6 +1341,7 @@ static ssize_t libc_sendmmsg(int sockfd,
 /* Linux */
 static int libc_sendmmsg(int sockfd, struct mmsghdr *msgvec, unsigned int vlen, int flags)
 #endif
+#endif
 {
 	swrap_bind_symbol_all();
 
@@ -7565,6 +7602,9 @@ ssize_t recvmsg(int sockfd, struct msghd
  ***************************************************************************/
 
 #ifdef HAVE_RECVMMSG
+#ifdef __NetBSD__
+static int swrap_recvmmsg(int s, struct mmsghdr *omsgvec, unsigned int _vlen, unsigned int flags, struct timespec *timeout)
+#else
 #if defined(HAVE_RECVMMSG_SSIZE_T_CONST_TIMEOUT)
 /* FreeBSD */
 static ssize_t swrap_recvmmsg(int s, struct mmsghdr *omsgvec, size_t _vlen, int flags, const struct timespec *timeout)
@@ -7575,6 +7615,7 @@ static int swrap_recvmmsg(int s, struct 
 /* Linux glibc >= 2.21 */
 static int swrap_recvmmsg(int s, struct mmsghdr *omsgvec, unsigned int _vlen, int flags, struct timespec *timeout)
 #endif
+#endif
 {
 	struct socket_info *si = find_socket_info(s);
 #define __SWRAP_RECVMMSG_MAX_VLEN 16
@@ -7758,6 +7799,9 @@ fail_swrap:
 	return ret;
 }
 
+#ifdef __NetBSD__
+int recvmmsg(int sockfd, struct mmsghdr *msgvec, unsigned int vlen, unsigned int flags, struct timespec *timeout)
+#else
 #if defined(HAVE_RECVMMSG_SSIZE_T_CONST_TIMEOUT)
 /* FreeBSD */
 ssize_t recvmmsg(int sockfd, struct mmsghdr *msgvec, size_t vlen, int flags, const struct timespec *timeout)
@@ -7768,6 +7812,7 @@ int recvmmsg(int sockfd, struct mmsghdr 
 /* Linux glibc >= 2.21 */
 int recvmmsg(int sockfd, struct mmsghdr *msgvec, unsigned int vlen, int flags, struct timespec *timeout)
 #endif
+#endif
 {
 	return swrap_recvmmsg(sockfd, msgvec, vlen, flags, timeout);
 }
@@ -7949,6 +7994,9 @@ ssize_t sendmsg(int s, const struct msgh
  ***************************************************************************/
 
 #ifdef HAVE_SENDMMSG
+#ifdef __NetBSD__
+static ssize_t swrap_sendmmsg(int s, struct mmsghdr *omsgvec, unsigned int _vlen, unsigned int flags)
+#else
 #if defined(HAVE_SENDMMSG_SSIZE_T)
 /* FreeBSD */
 static ssize_t swrap_sendmmsg(int s, struct mmsghdr *omsgvec, size_t _vlen, int flags)
@@ -7956,6 +8004,7 @@ static ssize_t swrap_sendmmsg(int s, str
 /* Linux */
 static int swrap_sendmmsg(int s, struct mmsghdr *omsgvec, unsigned int _vlen, int flags)
 #endif
+#endif
 {
 	struct socket_info *si = find_socket_info(s);
 #define __SWRAP_SENDMMSG_MAX_VLEN 16
@@ -8175,6 +8224,9 @@ fail_swrap:
 	return ret;
 }
 
+#ifdef __NetBSD__
+int sendmmsg(int s, struct mmsghdr *msgvec, unsigned int vlen, unsigned int flags)
+#else
 #if defined(HAVE_SENDMMSG_SSIZE_T)
 /* FreeBSD */
 ssize_t sendmmsg(int s, struct mmsghdr *msgvec, size_t vlen, int flags)
@@ -8182,6 +8234,7 @@ ssize_t sendmmsg(int s, struct mmsghdr *
 /* Linux */
 int sendmmsg(int s, struct mmsghdr *msgvec, unsigned int vlen, int flags)
 #endif
+#endif
 {
 	return swrap_sendmmsg(s, msgvec, vlen, flags);
 }
@@ -8936,6 +8989,7 @@ static void swrap_thread_child(void)
  ***************************/
 void swrap_constructor(void)
 {
+#ifdef __linux__
 	if (PIPE_BUF < sizeof(struct swrap_unix_scm_rights)) {
 		SWRAP_LOG(SWRAP_LOG_ERROR,
 			  "PIPE_BUF=%zu < "
@@ -8948,6 +9002,7 @@ void swrap_constructor(void)
 			  sizeof(struct socket_info));
 		exit(-1);
 	}
+#endif
 
 	SWRAP_REINIT_ALL;
 
