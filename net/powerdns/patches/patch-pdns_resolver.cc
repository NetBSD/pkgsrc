$NetBSD: patch-pdns_resolver.cc,v 1.1 2012/10/02 12:20:47 jperkin Exp $

Limit inclusion of boost headers to only those necessary to avoid conflicting
types errors on Solaris.

--- pdns/resolver.cc.orig	2012-01-05 13:54:51.000000000 +0000
+++ pdns/resolver.cc	2012-10-02 10:39:23.879764460 +0000
@@ -29,7 +29,7 @@
 #include <cstring>
 #include <string>
 #include <vector>
-#include <boost/algorithm/string.hpp>
+#include <boost/algorithm/string/erase.hpp>
 #include "dns.hh"
 #include "qtype.hh"
 #include "tcpreceiver.hh"
