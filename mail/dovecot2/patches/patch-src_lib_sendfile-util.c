$NetBSD: patch-src_lib_sendfile-util.c,v 1.1 2015/09/04 18:49:36 wiedi Exp $

The call to sendfile on SmartOS can fail with EOPNOTSUPP. This is a valid error
code and documented in the man page. This error code needs to be handled or
else dovecot will retry the sendfile call endlessly and hang.

This patch has been proposed upstream.

--- src/lib/sendfile-util.c.orig	2015-01-05 20:20:07.000000000 +0000
+++ src/lib/sendfile-util.c
@@ -116,7 +116,7 @@ ssize_t safe_sendfile(int out_fd, int in
 		if (errno == EINVAL) {
 			/* most likely trying to read past EOF */
 			ret = 0;
-		} else if (errno == EAFNOSUPPORT) {
+		} else if (errno == EAFNOSUPPORT || errno == EOPNOTSUPP) {
 			/* not supported, return Linux-like EINVAL so caller
 			   sees only consistent errnos. */
 			errno = EINVAL;
