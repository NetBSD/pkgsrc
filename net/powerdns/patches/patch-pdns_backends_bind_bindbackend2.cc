$NetBSD: patch-pdns_backends_bind_bindbackend2.cc,v 1.1 2012/10/02 12:20:47 jperkin Exp $

Limit inclusion of boost headers to only those necessary to avoid conflicting
types errors on Solaris.

--- pdns/backends/bind/bindbackend2.cc.orig	2012-01-05 13:54:51.000000000 +0000
+++ pdns/backends/bind/bindbackend2.cc	2012-10-02 10:41:01.017473672 +0000
@@ -26,8 +26,8 @@
 #include <fstream>
 #include <fcntl.h>
 #include <sstream>
-#include <boost/bind.hpp>
-#include <boost/algorithm/string.hpp>
+#include <boost/algorithm/string/erase.hpp>
+#include <boost/algorithm/string/trim.hpp>
 using namespace std;
 
 #include "dns.hh"
