$NetBSD: patch-kqueuemplexer.cc,v 1.1 2012/02/28 10:49:28 roy Exp $

kqueue systems normally have sys/event.h

--- kqueuemplexer.cc.orig	2010-09-21 16:22:09.000000000 +0000
+++ kqueuemplexer.cc
@@ -6,9 +6,7 @@
 #include <boost/lexical_cast.hpp>
 #include "syncres.hh"
 #include <sys/types.h>
-#ifdef __FreeBSD__ 
 #include <sys/event.h>
-#endif
 #include <sys/time.h>
 
 #include "namespaces.hh"
