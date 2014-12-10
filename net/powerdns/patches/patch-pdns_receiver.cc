$NetBSD: patch-pdns_receiver.cc,v 1.2 2014/12/10 14:50:09 fhajny Exp $

Limit inclusion of boost headers to only those necessary to avoid conflicting
types errors on Solaris.

--- pdns/receiver.cc.orig	2014-09-02 08:02:05.000000000 +0000
+++ pdns/receiver.cc
@@ -42,7 +42,7 @@
 #include <sys/mman.h>
 #include <fcntl.h>
 #include <fstream>
-#include <boost/algorithm/string.hpp>
+#include <boost/algorithm/string/trim.hpp>
 
 #include "config.h"
 #include "dns.hh"
