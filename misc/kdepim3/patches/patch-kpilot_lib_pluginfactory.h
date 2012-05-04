$NetBSD: patch-kpilot_lib_pluginfactory.h,v 1.1 2012/05/04 16:27:59 joerg Exp $

--- kpilot/lib/pluginfactory.h.orig	2012-04-27 15:41:25.000000000 +0000
+++ kpilot/lib/pluginfactory.h
@@ -31,15 +31,12 @@
 
 #include <kdebug.h>
 #include <klibloader.h>
+#include <kpilotlink.h>
 
 #include "options.h"
 
 /** @file Defines a template class for factories for KPilot's conduits. */
 
-class KPilotLink;
-
-
-
 /** Template class that defines a conduit's factory. */
 
 template <class Widget, class Action> class ConduitFactory : public KLibFactory
