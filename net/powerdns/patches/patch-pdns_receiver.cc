$NetBSD: patch-pdns_receiver.cc,v 1.4 2016/06/03 11:45:34 fhajny Exp $

Limit inclusion of boost headers to only those necessary to avoid conflicting
types errors on Solaris.

--- pdns/receiver.cc.orig	2016-05-13 16:04:50.000000000 +0000
+++ pdns/receiver.cc
@@ -42,7 +42,7 @@
 #include <sys/mman.h>
 #include <fcntl.h>
 #include <fstream>
-#include <boost/algorithm/string.hpp>
+#include <boost/algorithm/string/trim.hpp>
 #ifdef HAVE_OPENSSL
 #include "opensslsigners.hh"
 #endif
