$NetBSD: patch-res_pjproject_pjlib_src_pj_sock__select.c,v 1.1 2015/10/27 08:49:01 jnemeth Exp $

--- res/pjproject/pjlib/src/pj/sock_select.c.orig	2015-10-09 22:23:39.000000000 +0000
+++ res/pjproject/pjlib/src/pj/sock_select.c
@@ -40,10 +40,11 @@
 #define PART_FDSET_OR_NULL(ps)	(ps ? PART_FDSET(ps) : NULL)
 #define PART_COUNT(ps)		(ps->data[0])
 
+typedef char pj_assert_fd_set_t[(sizeof(pj_fd_set_t)-sizeof(pj_sock_t) >= sizeof(fd_set)) ? 1 : -1];
+
 PJ_DEF(void) PJ_FD_ZERO(pj_fd_set_t *fdsetp)
 {
     PJ_CHECK_STACK();
-    pj_assert(sizeof(pj_fd_set_t)-sizeof(pj_sock_t) >= sizeof(fd_set));
 
     FD_ZERO(PART_FDSET(fdsetp));
     PART_COUNT(fdsetp) = 0;
@@ -53,7 +54,6 @@ PJ_DEF(void) PJ_FD_ZERO(pj_fd_set_t *fds
 PJ_DEF(void) PJ_FD_SET(pj_sock_t fd, pj_fd_set_t *fdsetp)
 {
     PJ_CHECK_STACK();
-    pj_assert(sizeof(pj_fd_set_t)-sizeof(pj_sock_t) >= sizeof(fd_set));
 
     if (!PJ_FD_ISSET(fd, fdsetp))
         ++PART_COUNT(fdsetp);
@@ -64,7 +64,6 @@ PJ_DEF(void) PJ_FD_SET(pj_sock_t fd, pj_
 PJ_DEF(void) PJ_FD_CLR(pj_sock_t fd, pj_fd_set_t *fdsetp)
 {
     PJ_CHECK_STACK();
-    pj_assert(sizeof(pj_fd_set_t)-sizeof(pj_sock_t) >= sizeof(fd_set));
 
     if (PJ_FD_ISSET(fd, fdsetp))
         --PART_COUNT(fdsetp);
@@ -75,8 +74,6 @@ PJ_DEF(void) PJ_FD_CLR(pj_sock_t fd, pj_
 PJ_DEF(pj_bool_t) PJ_FD_ISSET(pj_sock_t fd, const pj_fd_set_t *fdsetp)
 {
     PJ_CHECK_STACK();
-    PJ_ASSERT_RETURN(sizeof(pj_fd_set_t)-sizeof(pj_sock_t) >= sizeof(fd_set),
-                     0);
 
     return FD_ISSET(fd, PART_FDSET(fdsetp));
 }
@@ -96,9 +93,6 @@ PJ_DEF(int) pj_sock_select( int n, 
 
     PJ_CHECK_STACK();
 
-    PJ_ASSERT_RETURN(sizeof(pj_fd_set_t)-sizeof(pj_sock_t) >= sizeof(fd_set),
-                     PJ_EBUG);
-
     if (timeout) {
 	os_timeout.tv_sec = timeout->sec;
 	os_timeout.tv_usec = timeout->msec * 1000;
