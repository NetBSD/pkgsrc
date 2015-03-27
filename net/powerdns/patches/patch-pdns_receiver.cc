$NetBSD: patch-pdns_receiver.cc,v 1.3 2015/03/27 23:37:52 rodent Exp $

Limit inclusion of boost headers to only those necessary to avoid conflicting
types errors on Solaris.

--- pdns/receiver.cc.orig	2015-03-02 13:17:12.000000000 +0000
+++ pdns/receiver.cc
@@ -42,7 +42,7 @@
 #include <sys/mman.h>
 #include <fcntl.h>
 #include <fstream>
-#include <boost/algorithm/string.hpp>
+#include <boost/algorithm/string/trim.hpp>
 
 #include "config.h"
 #include "dns.hh"
