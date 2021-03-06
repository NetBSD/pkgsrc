$NetBSD: patch-src_xdelta.cc,v 1.1 2021/03/06 08:57:54 nia Exp $

A function macro named E clashes with internal boost definitions.  Rearrange
the order of header inclusion so that affected boost headers are included
before monotone defines the macro.

Also, stop bundling boost/circular_buffer, which is available in current
versions of boost.

https://src.fedoraproject.org/fork/jjames/rpms/monotone/raw/84e80f1b992f0b0dba6cfe98eb9d0c55ea39623f/f/monotone-1.1-boost.patch

--- src/xdelta.cc.orig	2014-05-04 09:15:19.000000000 +0000
+++ src/xdelta.cc
@@ -26,7 +26,6 @@
 
 #include "base.hh"
 #include <algorithm>
-#include "vector.hh"
 #include <set>
 #include <sstream>
 #include <cstring>  // memcmp
@@ -34,6 +33,7 @@
 #include <boost/shared_ptr.hpp>
 #include <boost/version.hpp>
 
+#include "vector.hh"
 #include "adler32.hh"
 #include "hash_map.hh"
 #include "numeric_vocab.hh"
