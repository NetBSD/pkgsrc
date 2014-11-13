$NetBSD: patch-kleopatra_smartcard_readerstatus.cpp,v 1.1 2014/11/13 19:19:08 markd Exp $

Work around: Parse error at "BOOST_JOIN"

--- kleopatra/smartcard/readerstatus.cpp.orig	2014-11-06 08:45:47.000000000 +0000
+++ kleopatra/smartcard/readerstatus.cpp
@@ -58,11 +58,13 @@
 #include <QThread>
 #include <QPointer>
 
+#ifndef Q_MOC_RUN
 #include <boost/algorithm/string/split.hpp>
 #include <boost/algorithm/string/classification.hpp>
 #include <boost/algorithm/string/case_conv.hpp>
 #include <boost/static_assert.hpp>
 #include <boost/range.hpp>
+#endif
 #include <boost/bind.hpp>
 
 #include <vector>
