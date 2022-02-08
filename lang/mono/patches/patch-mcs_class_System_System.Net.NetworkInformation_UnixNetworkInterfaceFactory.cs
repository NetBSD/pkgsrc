$NetBSD: patch-mcs_class_System_System.Net.NetworkInformation_UnixNetworkInterfaceFactory.cs,v 1.1 2022/02/08 13:39:17 gavan Exp $

--- mcs/class/System/System.Net.NetworkInformation/UnixNetworkInterfaceFactory.cs.orig	2021-02-22 15:50:13.000000000 +0000
+++ mcs/class/System/System.Net.NetworkInformation/UnixNetworkInterfaceFactory.cs
@@ -43,7 +43,7 @@ namespace System.Net.NetworkInformation 
 			if (runningOnUnix) {
 				// XXX: OpenBSD and NetBSD too? It seems other platforms map closer to the Mac OS version than Linux,
 				// even if not exactly; it seems Linux and/or glibc are the different ones.
-				if (Platform.IsMacOS || Platform.IsOpenBSD)
+				if (Platform.IsMacOS || Platform.IsOpenBSD || Platform.IsNetBSD)
 					return new MacOsNetworkInterfaceAPI ();
 				if (Platform.IsFreeBSD)
 					return new FreeBSDNetworkInterfaceAPI ();
