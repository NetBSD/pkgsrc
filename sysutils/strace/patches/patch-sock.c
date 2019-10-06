$NetBSD: patch-sock.c,v 1.1 2019/10/06 17:45:50 christos Exp $

--- sock.c.orig	2005-06-01 15:02:37.000000000 -0400
+++ sock.c	2019-10-06 13:24:24.592475134 -0400
@@ -55,20 +55,42 @@
 	{ IFF_DEBUG,		"IFF_DEBUG"		},
 	{ IFF_LOOPBACK,		"IFF_LOOPBACK"		},
 	{ IFF_POINTOPOINT,	"IFF_POINTOPOINT"	},
+#ifdef IFF_NOTRAILERS
 	{ IFF_NOTRAILERS,	"IFF_NOTRAILERS"	},
+#endif
 	{ IFF_RUNNING,		"IFF_RUNNING"		},
 	{ IFF_NOARP,		"IFF_NOARP"		},
 	{ IFF_PROMISC,		"IFF_PROMISC"		},
 	{ IFF_ALLMULTI,		"IFF_ALLMULTI"		},
+#ifdef IFF_SIMPLEX
+	{ IFF_SIMPLEX,		"IFF_SIMPLEX"		},
+#endif
+#ifdef IFF_LINK0
+	{ IFF_LINK0,		"IFF_LINK0"		},
+#endif
+#ifdef IFF_LINK1
+	{ IFF_LINK1,		"IFF_LINK1"		},
+#endif
+#ifdef IFF_LINK2
+	{ IFF_LINK2,		"IFF_LINK2"		},
+#endif
+#ifdef IFF_MASTER
 	{ IFF_MASTER,		"IFF_MASTER"		},
+#endif
+#ifdef IFF_SLAVE
 	{ IFF_SLAVE,		"IFF_SLAVE"		},
+#endif
 	{ IFF_MULTICAST,	"IFF_MULTICAST"		},
+#ifdef IFF_PORTSEL
 	{ IFF_PORTSEL,		"IFF_PORTSEL"		},
+#endif
+#ifdef IFF_AUTOMEDIA
 	{ IFF_AUTOMEDIA,	"IFF_AUTOMEDIA"		},
+#endif
 	{ 0,			NULL			}
 };
 
-
+#ifndef ALLBSD
 static void
 print_addr(tcp, addr, ifr)
 struct tcb *tcp;
@@ -82,16 +104,19 @@
 	} else
 		printstr(tcp, addr, sizeof(ifr->ifr_addr.sa_data));
 }
+#endif
 
 int
 sock_ioctl(tcp, code, arg)
 struct tcb *tcp;
 long code, arg;
 {
-	struct ifreq ifr;
 	struct ifconf ifc;
+#ifndef ALLBSD
+	struct ifreq ifr;
 	const char *str = NULL;
 	unsigned char *bytes;
+#endif
 
 	if (entering(tcp)) {
 		if (code == SIOCGIFCONF) {
