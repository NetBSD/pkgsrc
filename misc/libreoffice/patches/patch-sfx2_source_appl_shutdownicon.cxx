$NetBSD: patch-sfx2_source_appl_shutdownicon.cxx,v 1.1 2018/12/14 13:12:24 ryoon Exp $

* Fix build with boost-1.69.0

--- sfx2/source/appl/shutdownicon.cxx.orig	2018-10-29 19:55:29.000000000 +0000
+++ sfx2/source/appl/shutdownicon.cxx
@@ -141,7 +141,7 @@ bool LoadModule()
 #endif // ENABLE_QUICKSTART_APPLET
     }
     assert(!boost::logic::indeterminate(loaded));
-    return loaded;
+    return bool(loaded);
 }
 
 }
