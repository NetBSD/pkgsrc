$NetBSD: patch-src_netcmd.hh,v 1.1 2021/03/06 08:57:54 nia Exp $

A function macro named E clashes with internal boost definitions.  Rearrange
the order of header inclusion so that affected boost headers are included
before monotone defines the macro.

Also, stop bundling boost/circular_buffer, which is available in current
versions of boost.

https://src.fedoraproject.org/fork/jjames/rpms/monotone/raw/84e80f1b992f0b0dba6cfe98eb9d0c55ea39623f/f/monotone-1.1-boost.patch

--- src/netcmd.hh.orig	2014-05-04 09:15:17.000000000 +0000
+++ src/netcmd.hh
@@ -10,13 +10,13 @@
 #ifndef __NETCMD_HH__
 #define __NETCMD_HH__
 
-#include "vector.hh"
 #include <list>
 #include <utility>
 #include <iostream>
 
-#include "globish.hh"
 #include "merkle_tree.hh"
+#include "vector.hh"
+#include "globish.hh"
 #include "numeric_vocab.hh"
 #include "uri.hh"
 #include "vocab.hh"
