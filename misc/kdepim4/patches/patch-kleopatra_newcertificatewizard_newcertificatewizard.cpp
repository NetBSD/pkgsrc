$NetBSD: patch-kleopatra_newcertificatewizard_newcertificatewizard.cpp,v 1.1 2014/11/13 19:19:08 markd Exp $

Work around: Parse error at "BOOST_JOIN"

--- kleopatra/newcertificatewizard/newcertificatewizard.cpp.orig	2014-11-06 08:45:47.000000000 +0000
+++ kleopatra/newcertificatewizard/newcertificatewizard.cpp
@@ -78,7 +78,9 @@
 #include <QUrl>
 #include <QDesktopServices>
 
+#ifndef Q_MOC_RUN
 #include <boost/range.hpp>
+#endif
 
 #include <algorithm>
 
