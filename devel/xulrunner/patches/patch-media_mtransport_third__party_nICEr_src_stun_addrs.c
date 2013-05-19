$NetBSD: patch-media_mtransport_third__party_nICEr_src_stun_addrs.c,v 1.1 2013/05/19 08:47:41 ryoon Exp $

--- media/mtransport/third_party/nICEr/src/stun/addrs.c.orig	2013-05-11 19:19:43.000000000 +0000
+++ media/mtransport/third_party/nICEr/src/stun/addrs.c
@@ -55,7 +55,9 @@ static char *RCSSTRING __UNUSED__="$Id: 
 #endif
 #include <net/if.h>
 #ifndef LINUX
+#if !defined(__OpenBSD__) && !defined(__NetBSD__)
 #include <net/if_var.h>
+#endif
 #include <net/if_dl.h>
 #include <net/if_types.h>
 #include <sys/sockio.h>
@@ -80,7 +82,7 @@ static char *RCSSTRING __UNUSED__="$Id: 
 
 
 
-#ifdef DARWIN
+#if defined(BSD) || defined(DARWIN)
 /*
  * Copyright (c) 1983, 1993
  *    The Regents of the University of California.  All rights reserved.
@@ -690,7 +692,7 @@ nr_stun_get_addrs(nr_transport_addr addr
     int _status=0;
     int i;
 
-#ifdef DARWIN
+#if defined(BSD) || defined(DARWIN)
     _status = stun_get_mib_addrs(addrs, maxaddrs, count);
 #elif defined(WIN32)
     _status = stun_get_win32_addrs(addrs, maxaddrs, count);
