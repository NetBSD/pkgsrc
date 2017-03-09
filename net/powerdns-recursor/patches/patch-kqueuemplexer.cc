$NetBSD: patch-kqueuemplexer.cc,v 1.3 2017/03/09 13:43:49 fhajny Exp $

kqueue systems normally have sys/event.h

--- kqueuemplexer.cc.orig	2017-01-13 08:55:55.000000000 +0000
+++ kqueuemplexer.cc
@@ -29,9 +29,7 @@
 #include "misc.hh"
 #include "syncres.hh"
 #include <sys/types.h>
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
 #include <sys/event.h>
-#endif
 #include <sys/time.h>
 
 #include "namespaces.hh"
