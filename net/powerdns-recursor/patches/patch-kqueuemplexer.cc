$NetBSD: patch-kqueuemplexer.cc,v 1.2 2015/06/10 14:22:29 fhajny Exp $

kqueue systems normally have sys/event.h

--- kqueuemplexer.cc.orig	2015-04-21 13:02:57.000000000 +0000
+++ kqueuemplexer.cc
@@ -6,9 +6,7 @@
 #include <boost/lexical_cast.hpp>
 #include "syncres.hh"
 #include <sys/types.h>
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
 #include <sys/event.h>
-#endif
 #include <sys/time.h>
 
 #include "namespaces.hh"
