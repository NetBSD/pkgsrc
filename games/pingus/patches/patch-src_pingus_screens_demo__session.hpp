$NetBSD: patch-src_pingus_screens_demo__session.hpp,v 1.1 2019/05/27 15:37:56 maya Exp $

Avoid build error:
src/pingus/screens/demo_session.cpp:41:8: error: 'function' in namespace 'std' does not name a template type
NetBSD-8.99.41 (GCC 7.4.0)

--- src/pingus/screens/demo_session.hpp.orig	2011-12-24 21:46:47.000000000 +0000
+++ src/pingus/screens/demo_session.hpp
@@ -19,6 +19,7 @@
 
 #include <memory>
 #include <vector>
+#include <functional>
 
 #include "engine/screen/gui_screen.hpp"
 #include "pingus/server_event.hpp"
