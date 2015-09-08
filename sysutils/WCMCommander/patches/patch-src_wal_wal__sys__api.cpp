$NetBSD: patch-src_wal_wal__sys__api.cpp,v 1.2 2015/09/08 13:21:46 wiz Exp $

Handle NetBSD like the other BSDs.
https://github.com/corporateshark/WCMCommander/pull/509

--- src/wal/wal_sys_api.cpp.orig	2015-04-24 21:50:22.000000000 +0000
+++ src/wal/wal_sys_api.cpp
@@ -394,6 +394,7 @@ namespace wal
 
 #if defined(__APPLE__) || \
    defined(__FreeBSD__) || \
+   defined(__NetBSD__) || \
    defined(__OpenBSD__) || \
    defined(_POSIX_C_SOURCE) && defined(_XOPEN_SOURCE) && defined(_GNU_SOURCE) && (_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && ! _GNU_SOURCE
 			strerror_r( err, buf, size );
