$NetBSD: patch-src_os_user_lookup__unix.go,v 1.2 2015/12/21 20:20:02 bsiegert Exp $

http://golang.org/cl/8261

--- src/os/user/lookup_unix.go.orig	2014-12-11 01:18:10.000000000 +0000
+++ src/os/user/lookup_unix.go
@@ -17,6 +17,7 @@
 )
 
 /*
+#cgo solaris CFLAGS: -D_POSIX_PTHREAD_SEMANTICS
 #include <unistd.h>
 #include <sys/types.h>
 #include <pwd.h>
@@ -24,7 +25,12 @@
 
 static int mygetpwuid_r(int uid, struct passwd *pwd,
 	char *buf, size_t buflen, struct passwd **result) {
- return getpwuid_r(uid, pwd, buf, buflen, result);
+	return getpwuid_r(uid, pwd, buf, buflen, result);
+}
+
+static int mygetpwnam_r(const char *name, struct passwd *pwd,
+	char *buf, size_t buflen, struct passwd **result) {
+	return getpwnam_r(name, pwd, buf, buflen, result);
 }
 */
 import "C"
@@ -67,7 +73,11 @@
 	if lookupByName {
 		nameC := C.CString(username)
 		defer C.free(unsafe.Pointer(nameC))
-		rv = C.getpwnam_r(nameC,
+		// mygetpwnam_r is a wrapper around getpwnam_r to avoid
+		// passing a size_t to getpwnam_r, because for unknown
+		// reasons passing a size_t to getpwnam_r doesn't work on
+		// Solaris.
+		rv = C.mygetpwnam_r(nameC,
 			&pwd,
 			(*C.char)(buf),
 			C.size_t(bufSize),
