$NetBSD: patch-src_asciik.hh,v 1.1 2021/03/06 08:57:54 nia Exp $

A function macro named E clashes with internal boost definitions.  Rearrange
the order of header inclusion so that affected boost headers are included
before monotone defines the macro.

Also, stop bundling boost/circular_buffer, which is available in current
versions of boost.

https://src.fedoraproject.org/fork/jjames/rpms/monotone/raw/84e80f1b992f0b0dba6cfe98eb9d0c55ea39623f/f/monotone-1.1-boost.patch

--- src/asciik.hh.orig	2014-05-04 09:15:15.000000000 +0000
+++ src/asciik.hh
@@ -11,8 +11,8 @@
 #define __ASCIIK_HH__
 
 #include <set>
-#include "vector.hh"
 #include "vocab.hh"
+#include "vector.hh"
 
 class asciik
 {
