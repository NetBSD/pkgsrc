$NetBSD: patch-lib_connections_quic__misc.go,v 1.1 2022/09/17 11:54:43 bsiegert Exp $

Go 1.19 compatibility.
https://github.com/syncthing/syncthing/pull/8483

--- lib/connections/quic_misc.go.orig	2022-08-02 08:19:47.000000000 +0000
+++ lib/connections/quic_misc.go
@@ -13,6 +13,7 @@ import (
 	"crypto/tls"
 	"net"
 	"net/url"
+	"time"
 
 	"github.com/lucas-clemente/quic-go"
 )
@@ -20,7 +21,8 @@ import (
 var (
 	quicConfig = &quic.Config{
 		ConnectionIDLength: 4,
-		KeepAlive:          true,
+		MaxIdleTimeout:     30 * time.Second,
+		KeepAlivePeriod:    15 * time.Second,
 	}
 )
 
