$NetBSD: patch-src_basic__io.hh,v 1.1 2021/03/06 08:57:54 nia Exp $

A function macro named E clashes with internal boost definitions.  Rearrange
the order of header inclusion so that affected boost headers are included
before monotone defines the macro.

Also, stop bundling boost/circular_buffer, which is available in current
versions of boost.

https://src.fedoraproject.org/fork/jjames/rpms/monotone/raw/84e80f1b992f0b0dba6cfe98eb9d0c55ea39623f/f/monotone-1.1-boost.patch

--- src/basic_io.hh.orig	2014-05-04 09:15:16.000000000 +0000
+++ src/basic_io.hh
@@ -11,11 +11,11 @@
 #ifndef __BASIC_IO_HH__
 #define __BASIC_IO_HH__
 
-#include "vector.hh"
 #include <map>
 
 #include "paths.hh"
 #include "sanity.hh"
+#include "vector.hh"
 #include "vocab.hh"
 #include "numeric_vocab.hh"
 #include "char_classifiers.hh"
