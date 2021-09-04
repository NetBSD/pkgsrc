$NetBSD: patch-vendor_github.com_godbus_dbus_v5_transport__unixcred__netbsd.go,v 1.1 2021/09/04 20:28:42 maya Exp $

Add netbsd support (vendor code)
Taken from openbsd example.

--- vendor/github.com/godbus/dbus/v5/transport_unixcred_netbsd.go.orig	2021-09-04 12:43:05.852290581 +0000
+++ vendor/github.com/godbus/dbus/v5/transport_unixcred_netbsd.go
@@ -0,0 +1,14 @@
+package dbus
+
+import "io"
+
+func (t *unixTransport) SendNullByte() error {
+	n, _, err := t.UnixConn.WriteMsgUnix([]byte{0}, nil, nil)
+	if err != nil {
+		return err
+	}
+	if n != 1 {
+		return io.ErrShortWrite
+	}
+	return nil
+}
