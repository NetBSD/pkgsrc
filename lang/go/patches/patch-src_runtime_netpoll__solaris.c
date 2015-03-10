$NetBSD: patch-src_runtime_netpoll__solaris.c,v 1.1 2015/03/10 13:11:36 jperkin Exp $

Support cgo on illumos.

--- src/runtime/netpoll_solaris.c.orig	2014-12-11 01:18:12.000000000 +0000
+++ src/runtime/netpoll_solaris.c
@@ -73,11 +73,14 @@
 #pragma dynimport libc·port_associate port_associate "libc.so"
 #pragma dynimport libc·port_dissociate port_dissociate "libc.so"
 #pragma dynimport libc·port_getn port_getn "libc.so"
-extern uintptr libc·fcntl;
-extern uintptr libc·port_create;
-extern uintptr libc·port_associate;
-extern uintptr libc·port_dissociate;
-extern uintptr libc·port_getn;
+
+typedef uintptr (extf)();
+
+extern extf libc·fcntl;
+extern extf libc·port_create;
+extern extf libc·port_associate;
+extern extf libc·port_dissociate;
+extern extf libc·port_getn;
 
 #define errno (*g->m->perrno)
 
