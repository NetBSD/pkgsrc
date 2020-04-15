$NetBSD: patch-libbeat_common_file_stderr__other.go,v 1.1 2020/04/15 13:00:55 jperkin Exp $

Use more portable unix.Dup2().

--- libbeat/common/file/stderr_other.go.orig	2020-03-05 13:27:52.000000000 +0000
+++ libbeat/common/file/stderr_other.go
@@ -21,11 +21,11 @@ package file
 
 import (
 	"os"
-	"syscall"
+	"golang.org/x/sys/unix"
 )
 
 // RedirectStandardError causes all standard error output to be directed to the
 // given file.
 func RedirectStandardError(toFile *os.File) error {
-	return syscall.Dup2(int(toFile.Fd()), 2)
+	return unix.Dup2(int(toFile.Fd()), 2)
 }
