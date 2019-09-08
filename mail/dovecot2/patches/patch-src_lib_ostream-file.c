$NetBSD: patch-src_lib_ostream-file.c,v 1.2.2.2 2019/09/08 17:11:50 bsiegert Exp $

Silence Error: file_ostream.net_set_tcp_nodelay(, TRUE) failed

Patch from upstream -head via FreeBSD
<https://svnweb.freebsd.org/ports/head/mail/dovecot/files/patch-src_lib_ostream-file.c?view=markup&pathrev=506487>

--- src/lib/ostream-file.c.orig	2019-07-12 10:46:25.000000000 +0000
+++ src/lib/ostream-file.c
@@ -334,7 +334,7 @@ static void o_stream_tcp_flush_via_nodel
 {
 	if (net_set_tcp_nodelay(fstream->fd, TRUE) < 0) {
 		if (errno != ENOTSUP && errno != ENOTSOCK &&
-		    errno != ENOPROTOOPT) {
+		    errno != ENOPROTOOPT && errno != EINVAL) {
 			i_error("file_ostream.net_set_tcp_nodelay(%s, TRUE) failed: %m",
 				o_stream_get_name(&fstream->ostream.ostream));
 		}
