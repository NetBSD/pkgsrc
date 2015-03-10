$NetBSD: patch-src_cmd_ld_doc.go,v 1.1 2015/03/10 13:11:36 jperkin Exp $

Support cgo on illumos.

--- src/cmd/ld/doc.go.orig	2014-12-11 01:18:12.000000000 +0000
+++ src/cmd/ld/doc.go
@@ -30,7 +30,7 @@ Options new in this version:
 		Elide the dynamic linking header.  With this option, the binary
 		is statically linked and does not refer to a dynamic linker.  Without this option
 		(the default), the binary's contents are identical but it is loaded with a dynamic
-		linker. This flag cannot be used when $GOOS is windows.
+		linker. This flag cannot be used when $GOOS is windows or solaris
 	-H darwin     (only in 6l/8l)
 		Write Apple Mach-O binaries (default when $GOOS is darwin)
 	-H dragonfly  (only in 6l/8l)
