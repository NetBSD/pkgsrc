$NetBSD: patch-pdns_receiver.cc,v 1.1 2012/10/02 12:20:47 jperkin Exp $

Limit inclusion of boost headers to only those necessary to avoid conflicting
types errors on Solaris.

--- pdns/receiver.cc.orig	2012-01-05 13:54:51.000000000 +0000
+++ pdns/receiver.cc	2012-10-02 10:37:52.894235670 +0000
@@ -39,7 +39,7 @@
 #include <sys/mman.h>
 #include <fcntl.h>
 #include <fstream>
-#include <boost/algorithm/string.hpp>
+#include <boost/algorithm/string/trim.hpp>
 
 #include "config.h"
 #include "dns.hh"
