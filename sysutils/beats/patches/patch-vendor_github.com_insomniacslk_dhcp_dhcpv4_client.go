$NetBSD: patch-vendor_github.com_insomniacslk_dhcp_dhcpv4_client.go,v 1.1 2019/03/15 15:03:02 he Exp $

BindToInterface is apparently only implemented for Linux and Darwin.
So much for portable software.  Since I fail to grasp what dhcp has
to do with shipping logs, just comment out the code to make it build.

--- vendor/github.com/insomniacslk/dhcp/dhcpv4/client.go.orig	2019-03-06 10:13:10.000000000 +0000
+++ vendor/github.com/insomniacslk/dhcp/dhcpv4/client.go
@@ -90,10 +90,10 @@ func MakeBroadcastSocket(ifname string) 
 	if err != nil {
 		return fd, err
 	}
-	err = BindToInterface(fd, ifname)
-	if err != nil {
-		return fd, err
-	}
+//	err = BindToInterface(fd, ifname)
+//	if err != nil {
+//		return fd, err
+//	}
 	return fd, nil
 }
 
@@ -113,10 +113,10 @@ func MakeListeningSocket(ifname string) 
 	if err = syscall.Bind(fd, &syscall.SockaddrInet4{Port: ClientPort, Addr: addr}); err != nil {
 		return fd, err
 	}
-	err = BindToInterface(fd, ifname)
-	if err != nil {
-		return fd, err
-	}
+//	err = BindToInterface(fd, ifname)
+//	if err != nil {
+//		return fd, err
+//	}
 	return fd, nil
 }
 
