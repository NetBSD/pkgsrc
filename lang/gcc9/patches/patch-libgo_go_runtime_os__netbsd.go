$NetBSD: patch-libgo_go_runtime_os__netbsd.go,v 1.1 2020/04/20 14:25:52 bsiegert Exp $

Fix compilation errors under NetBSD. Taken from upstream Go 1.14 sources.

--- libgo/go/runtime/os_netbsd.go.orig	2020-03-12 11:07:24.000000000 +0000
+++ libgo/go/runtime/os_netbsd.go
@@ -52,11 +52,11 @@ func semasleep(ns int64) int32 {
 				return -1
 			}
 			var nsec int32
-			ts.set_sec(timediv(wait, 1000000000, &nsec))
+			ts.set_sec(int64(timediv(wait, 1000000000, &nsec)))
 			ts.set_nsec(nsec)
 			tsp = &ts
 		}
-		ret := lwp_park(_CLOCK_MONOTONIC, _TIMER_RELTIME, tsp, 0, unsafe.Pointer(&_g_.m.waitsemacount), nil)
+		ret := lwp_park(_CLOCK_MONOTONIC, _TIMER_RELTIME, tsp, 0, unsafe.Pointer(&_g_.m.mos.waitsemacount), nil)
 		if ret == _ETIMEDOUT {
 			return -1
 		}
@@ -77,3 +77,34 @@ func semawakeup(mp *m) {
 		})
 	}
 }
+
+func sysargs(argc int32, argv **byte) {
+	n := argc + 1
+
+	// skip over argv, envp to get to auxv
+	for argv_index(argv, n) != nil {
+		n++
+	}
+
+	// skip NULL separator
+	n++
+
+	// now argv+n is auxv
+	auxv := (*[1 << 28]uintptr)(add(unsafe.Pointer(argv), uintptr(n)*sys.PtrSize))
+	sysauxv(auxv[:])
+}
+
+const (
+	_AT_NULL   = 0 // Terminates the vector
+	_AT_PAGESZ = 6 // Page size in bytes
+)
+
+func sysauxv(auxv []uintptr) {
+	for i := 0; auxv[i] != _AT_NULL; i += 2 {
+		tag, val := auxv[i], auxv[i+1]
+		switch tag {
+		case _AT_PAGESZ:
+			physPageSize = val
+		}
+	}
+}
