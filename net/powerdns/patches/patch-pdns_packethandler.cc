$NetBSD: patch-pdns_packethandler.cc,v 1.1 2012/10/02 12:20:47 jperkin Exp $

Limit inclusion of boost headers to only those necessary to avoid conflicting
types errors on Solaris.

--- pdns/packethandler.cc.orig	2012-01-05 13:54:51.000000000 +0000
+++ pdns/packethandler.cc	2012-10-02 10:36:35.971513178 +0000
@@ -19,7 +19,7 @@
 #include "utility.hh"
 #include <string>
 #include <sys/types.h>
-#include <boost/algorithm/string.hpp>
+#include <boost/algorithm/string/predicate.hpp>
 #include "dns.hh"
 #include "dnsbackend.hh"
 #include "ueberbackend.hh"
