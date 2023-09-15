$NetBSD: patch-.._.._pkg_transport_listen__netbsd.go,v 1.3 2023/09/15 17:56:09 tnn Exp $

Port to NetBSD

--- pkg/transport/listen_netbsd.go.orig	2023-09-15 15:16:45.071862574 +0000
+++ pkg/transport/listen_netbsd.go
@@ -0,0 +1,55 @@
+package transport
+
+import (
+	"errors"
+	"fmt"
+	"net"
+	"net/url"
+	"os"
+	"path"
+	"strconv"
+)
+
+const DefaultURL = "vsock://:1024/"
+
+func Listen(endpoint string) (net.Listener, error) {
+	parsed, err := url.Parse(endpoint)
+	if err != nil {
+		return nil, err
+	}
+	switch parsed.Scheme {
+	case "vsock":
+		port, err := strconv.Atoi(parsed.Port())
+		if err != nil {
+			return nil, err
+		}
+		path := path.Join(parsed.Path, fmt.Sprintf("00000002.%08x", port))
+		if err := os.Remove(path); err != nil && !os.IsNotExist(err) {
+			return nil, err
+		}
+		return net.ListenUnix("unix", &net.UnixAddr{
+			Name: path,
+			Net:  "unix",
+		})
+	case "unix":
+		return net.Listen("unix", parsed.Path)
+	case "tcp":
+		return net.Listen("tcp", parsed.Host)
+	default:
+		return nil, errors.New("unexpected scheme")
+	}
+}
+
+func ListenUnixgram(endpoint string) (*net.UnixConn, error) {
+	parsed, err := url.Parse(endpoint)
+	if err != nil {
+		return nil, err
+	}
+	if parsed.Scheme != "unixgram" {
+		return nil, errors.New("unexpected scheme")
+	}
+	return net.ListenUnixgram("unixgram", &net.UnixAddr{
+		Name: parsed.Path,
+		Net:  "unixgram",
+	})
+}
