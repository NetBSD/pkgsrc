$NetBSD: patch-src_database.cc,v 1.3 2021/03/06 08:57:54 nia Exp $

A function macro named E clashes with internal boost definitions.  Rearrange
the order of header inclusion so that affected boost headers are included
before monotone defines the macro.

Also, stop bundling boost/circular_buffer, which is available in current
versions of boost.

https://src.fedoraproject.org/fork/jjames/rpms/monotone/raw/84e80f1b992f0b0dba6cfe98eb9d0c55ea39623f/f/monotone-1.1-boost.patch

--- src/database.cc.orig	2014-05-04 09:15:16.000000000 +0000
+++ src/database.cc
@@ -17,13 +17,13 @@
 #include <numeric>
 #include <set>
 #include <sstream>
-#include "vector.hh"
 
 #include <string.h>
 #include <boost/bind.hpp>
 #include <boost/shared_ptr.hpp>
 #include <boost/tuple/tuple.hpp>
 #include <boost/tuple/tuple_comparison.hpp>
+#include "vector.hh"
 
 #include <botan/botan.h>
 #include <botan/rsa.h>
