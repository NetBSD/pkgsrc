$NetBSD: patch-repmgr_repmgr__posix.c,v 1.1 2014/06/07 08:17:52 obache Exp $

* avoid to conflict with "struct iovec" defined in sys/uio.h.

--- repmgr/repmgr_posix.c.orig	2010-04-12 20:25:35.000000000 +0000
+++ repmgr/repmgr_posix.c
@@ -488,15 +488,15 @@ __repmgr_wake_main_thread(env)
  * PUBLIC: int __repmgr_writev __P((socket_t, db_iovec_t *, int, size_t *));
  */
 int
-__repmgr_writev(fd, iovec, buf_count, byte_count_p)
+__repmgr_writev(fd, iovec_p, buf_count, byte_count_p)
 	socket_t fd;
-	db_iovec_t *iovec;
+	db_iovec_t *iovec_p;
 	int buf_count;
 	size_t *byte_count_p;
 {
 	int nw;
 
-	if ((nw = writev(fd, iovec, buf_count)) == -1)
+	if ((nw = writev(fd, iovec_p, buf_count)) == -1)
 		return (errno);
 	*byte_count_p = (size_t)nw;
 	return (0);
@@ -506,15 +506,15 @@ __repmgr_writev(fd, iovec, buf_count, by
  * PUBLIC: int __repmgr_readv __P((socket_t, db_iovec_t *, int, size_t *));
  */
 int
-__repmgr_readv(fd, iovec, buf_count, byte_count_p)
+__repmgr_readv(fd, iovec_p, buf_count, byte_count_p)
 	socket_t fd;
-	db_iovec_t *iovec;
+	db_iovec_t *iovec_p;
 	int buf_count;
 	size_t *byte_count_p;
 {
 	ssize_t nw;
 
-	if ((nw = readv(fd, iovec, buf_count)) == -1)
+	if ((nw = readv(fd, iovec_p, buf_count)) == -1)
 		return (errno);
 	*byte_count_p = (size_t)nw;
 	return (0);
