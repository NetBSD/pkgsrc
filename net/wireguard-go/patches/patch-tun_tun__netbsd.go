$NetBSD: patch-tun_tun__netbsd.go,v 1.1 2023/12/14 13:56:23 adam Exp $

Enables multi-af mode for NetBSD tun(4).

--- tun/tun_netbsd.go.orig	2023-07-03 19:33:35.358738005 +0000
+++ tun/tun_netbsd.go
@@ -25,7 +25,7 @@ type ifreq_mtu struct {
 	Pad0 [12]byte
 }
 
-const _TUNSIFMODE = 0x8004745d
+const _TUNSIFHEAD = 0x80047442
 
 type NativeTun struct {
 	name        string
@@ -130,6 +130,22 @@ func CreateTUN(name string, mtu int) (De
 
 	tun, err := CreateTUNFromFile(tunfile, mtu)
 
+	// set multi-af mode
+	ifheadmode := 1
+	var errno syscall.Errno
+	_, _, errno = unix.Syscall(
+		unix.SYS_IOCTL,
+		tunfile.Fd(),
+		uintptr(_TUNSIFHEAD),
+		uintptr(unsafe.Pointer(&ifheadmode)),
+	)
+
+	if errno != 0 {
+		tunfile.Close()
+		return nil, fmt.Errorf("Unable to put into multi-af mode: %v", errno)
+	}
+
+
 	if err == nil && name == "tun" {
 		fname := os.Getenv("WG_TUN_NAME_FILE")
 		if fname != "" {
