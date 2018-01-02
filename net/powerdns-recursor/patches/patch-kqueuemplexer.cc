$NetBSD: patch-kqueuemplexer.cc,v 1.4 2018/01/02 12:23:55 fhajny Exp $

kqueue systems normally have sys/event.h

--- kqueuemplexer.cc.orig	2017-12-04 12:51:03.000000000 +0000
+++ kqueuemplexer.cc
@@ -28,9 +28,7 @@
 #include <unistd.h>
 #include "misc.hh"
 #include <sys/types.h>
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
 #include <sys/event.h>
-#endif
 #include <sys/time.h>
 
 #include "namespaces.hh"
