$NetBSD: patch-PctestIpv6Tcp.cc,v 1.1 2014/02/24 12:49:56 wiedi Exp $

don't define _XOPEN_SOURCE and __EXTENSIONS__ at the same time
--- PctestIpv6Tcp.cc.orig	2005-02-12 20:32:18.000000000 +0000
+++ PctestIpv6Tcp.cc
@@ -22,7 +22,6 @@ static char rcsid[] = "$Id: PctestIpv6Tc
 // according to Erik Nordmark <Erik.Nordmark@eng.sun.com>.  His quick
 // fix to do this is:
 #ifdef NEED_XOPEN
-#define _XOPEN_SOURCE 500
 #define __EXTENSIONS__
 #endif /* NEED_XOPEN */
 
