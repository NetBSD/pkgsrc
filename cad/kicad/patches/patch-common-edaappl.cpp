$NetBSD: patch-common-edaappl.cpp,v 1.1.1.1 2014/02/17 20:38:59 bouyer Exp $

Building on Mac OS X requires CoreFoundation headers.

--- common/edaappl.cpp.orig	2014-02-14 21:55:49.000000000 +0100
+++ common/edaappl.cpp	2014-02-14 22:39:14.000000000 +0100
@@ -41,6 +41,10 @@
 #include <wx/snglinst.h>
 #include <wx/tokenzr.h>
 
+#ifdef __DARWIN__
+#include <CoreFoundation/CFBundle.h>
+#endif
+
 #include <appl_wxstruct.h>
 #include <wxstruct.h>
 #include <macros.h>
