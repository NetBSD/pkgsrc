$NetBSD: patch-src_sha1.cc,v 1.1 2021/03/06 08:57:54 nia Exp $

A function macro named E clashes with internal boost definitions.  Rearrange
the order of header inclusion so that affected boost headers are included
before monotone defines the macro.

Also, stop bundling boost/circular_buffer, which is available in current
versions of boost.

https://src.fedoraproject.org/fork/jjames/rpms/monotone/raw/84e80f1b992f0b0dba6cfe98eb9d0c55ea39623f/f/monotone-1.1-boost.patch

--- src/sha1.cc.orig	2014-05-04 09:15:18.000000000 +0000
+++ src/sha1.cc
@@ -22,10 +22,10 @@
   #include <botan/benchmark.h>
 #endif
 
-#include "sanity.hh"
-#include "ui.hh"
 #include "platform.hh"
 #include "cmd.hh"
+#include "sanity.hh"
+#include "ui.hh"
 #include "transforms.hh"
 
 using std::string;
