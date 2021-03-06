$NetBSD: patch-src_rcs__import.cc,v 1.1 2021/03/06 08:57:54 nia Exp $

A function macro named E clashes with internal boost definitions.  Rearrange
the order of header inclusion so that affected boost headers are included
before monotone defines the macro.

Also, stop bundling boost/circular_buffer, which is available in current
versions of boost.

https://src.fedoraproject.org/fork/jjames/rpms/monotone/raw/84e80f1b992f0b0dba6cfe98eb9d0c55ea39623f/f/monotone-1.1-boost.patch

--- src/rcs_import.cc.orig	2014-05-04 09:15:17.000000000 +0000
+++ src/rcs_import.cc
@@ -16,13 +16,13 @@
 #include <sstream>
 #include <stack>
 #include <stdexcept>
-#include "vector.hh"
 #include <cstring> // memset
 
 #include <boost/shared_ptr.hpp>
 #include <boost/scoped_ptr.hpp>
 #include "lexical_cast.hh"
 #include <boost/tokenizer.hpp>
+#include "vector.hh"
 
 #include "cert.hh"
 #include "constants.hh"
