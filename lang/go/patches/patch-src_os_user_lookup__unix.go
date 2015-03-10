$NetBSD: patch-src_os_user_lookup__unix.go,v 1.1 2015/03/10 13:11:36 jperkin Exp $

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
