$NetBSD: patch-src_rcs__file.hh,v 1.1 2021/03/06 08:57:54 nia Exp $

A function macro named E clashes with internal boost definitions.  Rearrange
the order of header inclusion so that affected boost headers are included
before monotone defines the macro.

Also, stop bundling boost/circular_buffer, which is available in current
versions of boost.

https://src.fedoraproject.org/fork/jjames/rpms/monotone/raw/84e80f1b992f0b0dba6cfe98eb9d0c55ea39623f/f/monotone-1.1-boost.patch

--- src/rcs_file.hh.orig	2014-05-04 09:15:17.000000000 +0000
+++ src/rcs_file.hh
@@ -10,9 +10,9 @@
 #ifndef __RCS_FILE_HH__
 #define __RCS_FILE_HH__
 
-#include "vector.hh"
 #include <map>
 #include <boost/shared_ptr.hpp>
+#include "vector.hh"
 
 struct rcs_admin
 {
