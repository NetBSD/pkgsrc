$NetBSD: patch-src_os_user_lookup__unix.go,v 1.1 2015/07/31 14:46:25 bsiegert Exp $

Support cgo on illumos.

--- src/os/user/lookup_unix.go.orig	2014-12-11 01:18:10.000000000 +0000
+++ src/os/user/lookup_unix.go
@@ -17,6 +17,7 @@ import (
 )
 
 /*
+#cgo solaris CFLAGS: -D_POSIX_PTHREAD_SEMANTICS
 #include <unistd.h>
 #include <sys/types.h>
 #include <pwd.h>
