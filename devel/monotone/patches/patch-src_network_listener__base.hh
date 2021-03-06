$NetBSD: patch-src_network_listener__base.hh,v 1.1 2021/03/06 08:57:54 nia Exp $

A function macro named E clashes with internal boost definitions.  Rearrange
the order of header inclusion so that affected boost headers are included
before monotone defines the macro.

Also, stop bundling boost/circular_buffer, which is available in current
versions of boost.

https://src.fedoraproject.org/fork/jjames/rpms/monotone/raw/84e80f1b992f0b0dba6cfe98eb9d0c55ea39623f/f/monotone-1.1-boost.patch

--- src/network/listener_base.hh.orig	2014-05-04 09:15:17.000000000 +0000
+++ src/network/listener_base.hh
@@ -11,10 +11,10 @@
 #ifndef __LISTENER_BASE_HH__
 #define __LISTENER_BASE_HH__
 
-#include "reactable.hh"
-
 #include <boost/shared_ptr.hpp>
 
+#include "reactable.hh"
+
 // This is not currently needed because there's only one kind of listener.
 // But it's already here and not hurting anything, and might be useful if
 // we want to add another kind of listener later (something that accepts
