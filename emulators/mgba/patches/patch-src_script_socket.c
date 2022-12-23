$NetBSD: patch-src_script_socket.c,v 1.1 2022/12/23 12:20:47 nia Exp $

NetBSD 9 does not define ENOTRECOVERABLE (it is part of "robust
mutexes", not sockets).

--- src/script/socket.c.orig	2022-10-12 03:30:00.000000000 +0000
+++ src/script/socket.c
@@ -28,7 +28,9 @@ static const struct _mScriptSocketErrorM
 	{ ECONNREFUSED,          mSCRIPT_SOCKERR_CONNECTION_REFUSED },
 	{ EACCES,                mSCRIPT_SOCKERR_DENIED },
 	{ EPERM,                 mSCRIPT_SOCKERR_DENIED },
+#ifdef ENOTRECOVERABLE
 	{ ENOTRECOVERABLE,       mSCRIPT_SOCKERR_FAILED },
+#endif
 	{ ENETUNREACH,           mSCRIPT_SOCKERR_NETWORK_UNREACHABLE },
 	{ ETIMEDOUT,             mSCRIPT_SOCKERR_TIMEOUT },
 	{ EINVAL,                mSCRIPT_SOCKERR_UNSUPPORTED },
