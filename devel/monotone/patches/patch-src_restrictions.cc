$NetBSD: patch-src_restrictions.cc,v 1.1 2021/03/06 08:57:54 nia Exp $

A function macro named E clashes with internal boost definitions.  Rearrange
the order of header inclusion so that affected boost headers are included
before monotone defines the macro.

Also, stop bundling boost/circular_buffer, which is available in current
versions of boost.

https://src.fedoraproject.org/fork/jjames/rpms/monotone/raw/84e80f1b992f0b0dba6cfe98eb9d0c55ea39623f/f/monotone-1.1-boost.patch

--- src/restrictions.cc.orig	2014-05-04 09:15:17.000000000 +0000
+++ src/restrictions.cc
@@ -8,9 +8,9 @@
 // PURPOSE.
 
 #include "base.hh"
+#include "restrictions.hh"
 #include "safe_map.hh"
 #include "vector.hh"
-#include "restrictions.hh"
 #include "file_io.hh"
 #include "roster.hh"
 #include "database.hh" // for parent_roster
