$NetBSD: patch-collector_cpu__netbsd.go,v 1.3 2024/08/05 00:55:21 tnn Exp $

collector/cpu_netbsd: fix 32-bit host support and plug memory leak
https://github.com/prometheus/node_exporter/pull/3083

--- collector/cpu_netbsd.go.orig	2024-07-14 11:52:11.000000000 +0000
+++ collector/cpu_netbsd.go
@@ -33,6 +33,15 @@ import (
 	"howett.net/plist"
 )
 
+const (
+	_IOC_OUT        = uint(0x40000000)
+	_IOC_IN         = uint(0x80000000)
+	_IOC_INOUT      = (_IOC_IN | _IOC_OUT)
+	_IOCPARM_MASK   = uint(0x1fff)
+	_IOCPARM_SHIFT  = uint(16)
+	_IOCGROUP_SHIFT = uint(8)
+)
+
 type clockinfo struct {
 	hz     int32 // clock frequency
 	tick   int32 // micro-seconds per hz tick
@@ -51,7 +60,7 @@ type cputime struct {
 
 type plistref struct {
 	pref_plist unsafe.Pointer
-	pref_len   uint64
+	pref_len   uint
 }
 
 type sysmonValues struct {
@@ -65,25 +74,19 @@ type sysmonProperty []sysmonValues
 
 type sysmonProperties map[string]sysmonProperty
 
-func readBytes(ptr unsafe.Pointer, length uint64) []byte {
-	buf := make([]byte, length-1)
-	var i uint64
-	for ; i < length-1; i++ {
-		buf[i] = *(*byte)(unsafe.Pointer(uintptr(ptr) + uintptr(i)))
-	}
-	return buf
+func _IOC(inout uint, group byte, num uint, len uintptr) uint {
+	return ((inout) | ((uint(len) & _IOCPARM_MASK) << _IOCPARM_SHIFT) | (uint(group) << _IOCGROUP_SHIFT) | (num))
 }
 
-func ioctl(fd int, nr int64, typ byte, size uintptr, retptr unsafe.Pointer) error {
+func _IOWR(group byte, num uint, len uintptr) uint {
+	return _IOC(_IOC_INOUT, group, num, len)
+}
+
+func ioctl(fd int, nr uint, typ byte, size uintptr, retptr unsafe.Pointer) error {
 	_, _, errno := unix.Syscall(
 		unix.SYS_IOCTL,
 		uintptr(fd),
-		// Some magicks derived from sys/ioccom.h.
-		uintptr((0x40000000|0x80000000)|
-			((int64(size)&(1<<13-1))<<16)|
-			(int64(typ)<<8)|
-			nr,
-		),
+		uintptr(_IOWR(typ, nr, size)),
 		uintptr(retptr),
 	)
 	if errno != 0 {
@@ -93,7 +96,7 @@ func ioctl(fd int, nr int64, typ byte, s
 }
 
 func readSysmonProperties() (sysmonProperties, error) {
-	fd, err := unix.Open(rootfsFilePath("/dev/sysmon"), unix.O_RDONLY, 0777)
+	fd, err := unix.Open(rootfsFilePath("/dev/sysmon"), unix.O_RDONLY, 0)
 	if err != nil {
 		return nil, err
 	}
@@ -104,8 +107,8 @@ func readSysmonProperties() (sysmonPrope
 	if err = ioctl(fd, 0, 'E', unsafe.Sizeof(retptr), unsafe.Pointer(&retptr)); err != nil {
 		return nil, err
 	}
-
-	bytes := readBytes(retptr.pref_plist, retptr.pref_len)
+	defer unix.Syscall(unix.SYS_MUNMAP, uintptr(retptr.pref_plist), uintptr(retptr.pref_len), uintptr(0))
+	bytes := unsafe.Slice((*byte)(unsafe.Pointer(retptr.pref_plist)), retptr.pref_len-1)
 
 	var props sysmonProperties
 	if _, err = plist.Unmarshal(bytes, &props); err != nil {
@@ -180,7 +183,7 @@ func getCPUTimes() ([]cputime, error) {
 	if err != nil {
 		return nil, err
 	}
-	ncpus := *(*int)(unsafe.Pointer(&ncpusb[0]))
+	ncpus := int(*(*uint32)(unsafe.Pointer(&ncpusb[0])))
 
 	if ncpus < 1 {
 		return nil, errors.New("Invalid cpu number")
@@ -192,10 +195,10 @@ func getCPUTimes() ([]cputime, error) {
 		if err != nil {
 			return nil, err
 		}
-		for len(cpb) >= int(unsafe.Sizeof(int(0))) {
-			t := *(*int)(unsafe.Pointer(&cpb[0]))
+		for len(cpb) >= int(unsafe.Sizeof(uint64(0))) {
+			t := *(*uint64)(unsafe.Pointer(&cpb[0]))
 			times = append(times, float64(t)/cpufreq)
-			cpb = cpb[unsafe.Sizeof(int(0)):]
+			cpb = cpb[unsafe.Sizeof(uint64(0)):]
 		}
 	}
 
