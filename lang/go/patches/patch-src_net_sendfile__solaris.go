$NetBSD: patch-src_net_sendfile__solaris.go,v 1.1 2015/08/25 21:02:52 fhajny Exp $

Since sendfile ends up being called in 3rd party software, we need
the library linked here. This fixes building other software that uses
net on SunOS.

--- src/net/sendfile_solaris.go.orig	2015-08-19 06:05:19.000000000 +0000
+++ src/net/sendfile_solaris.go
@@ -14,6 +14,8 @@ import (
 //go:cgo_import_dynamic _ _ "libsendfile.so"
 //go:cgo_import_dynamic _ _ "libsocket.so"
 
+//go:cgo_ldflag "-lsendfile"
+
 // maxSendfileSize is the largest chunk size we ask the kernel to copy
 // at a time.
 const maxSendfileSize int = 4 << 20
