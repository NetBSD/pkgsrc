$NetBSD: patch-src_roster.cc,v 1.1 2021/03/06 08:57:54 nia Exp $

A function macro named E clashes with internal boost definitions.  Rearrange
the order of header inclusion so that affected boost headers are included
before monotone defines the macro.

Also, stop bundling boost/circular_buffer, which is available in current
versions of boost.

https://src.fedoraproject.org/fork/jjames/rpms/monotone/raw/84e80f1b992f0b0dba6cfe98eb9d0c55ea39623f/f/monotone-1.1-boost.patch

--- src/roster.cc.orig	2014-05-04 09:15:18.000000000 +0000
+++ src/roster.cc
@@ -11,10 +11,10 @@
 #include "base.hh"
 #include <algorithm>
 #include <set>
-#include "vector.hh"
 #include <sstream>
 
 #include "basic_io.hh"
+#include "vector.hh"
 #include "cset.hh"
 #include "database.hh"
 #include "platform-wrapped.hh"
