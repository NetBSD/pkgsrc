$NetBSD: patch-src_syscall_syscall__darwin__amd64.go,v 1.1 2016/10/04 18:45:22 bsiegert Exp $

Support Mac OS Sierra. https://github.com/golang/go/issues/16352

--- src/syscall/syscall_darwin_amd64.go.orig	2015-09-23 04:37:37.000000000 +0000
+++ src/syscall/syscall_darwin_amd64.go
@@ -26,14 +26,21 @@ func NsecToTimeval(nsec int64) (tv Timev
 }
 
 //sysnb	gettimeofday(tp *Timeval) (sec int64, usec int32, err error)
-func Gettimeofday(tv *Timeval) (err error) {
-	// The tv passed to gettimeofday must be non-nil
-	// but is otherwise unused.  The answers come back
-	// in the two registers.
+func Gettimeofday(tv *Timeval) error {
+	// The tv passed to gettimeofday must be non-nil.
+	// Before macOS Sierra (10.12), tv was otherwise unused and
+	// the answers came back in the two registers.
+	// As of Sierra, gettimeofday return zeros and populates
+	// tv itself.
 	sec, usec, err := gettimeofday(tv)
-	tv.Sec = sec
-	tv.Usec = usec
-	return err
+	if err != nil {
+		return err
+	}
+	if sec != 0 || usec != 0 {
+		tv.Sec = sec
+		tv.Usec = usec
+	}
+	return nil
 }
 
 func SetKevent(k *Kevent_t, fd, mode, flags int) {
