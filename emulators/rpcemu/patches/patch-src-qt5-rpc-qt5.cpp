$NetBSD: patch-src-qt5-rpc-qt5.cpp,v 1.1 2020/10/24 16:33:34 js Exp $

The qmake .pro only includes certain files when on Linux or Windows, but the
code always assumes it's there, resulting in linker errors.

--- src/qt5/rpc-qt5.cpp.orig	2020-05-06 19:19:23.000000000 +0000
+++ src/qt5/rpc-qt5.cpp
@@ -554,6 +554,7 @@ Emulator::mainemuloop()
 			inscount = 0;
 		}
 
+#ifdef CONFIG_SLIRP
 		// If NAT networking, poll, but not too often
 		if (config.network_type == NetworkType_NAT) {
 			network_nat_rate++;
@@ -561,6 +562,7 @@ Emulator::mainemuloop()
 				network_nat_poll();
 			}
 		}
+#endif
 	}
 
 	// Perform clean-up and finalising actions
@@ -924,9 +926,11 @@ Emulator::network_config_updated(Network
 	QByteArray ba_ipaddress = ipaddress.toUtf8();
 	const char *ip_address = ba_ipaddress.constData();
 
+#ifdef CONFIG_NETWORK
 	if (network_config_changed(network_type, bridge_name, ip_address)) {
 		this->reset();
 	}
+#endif
 }
 
 /**
