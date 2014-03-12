$NetBSD: patch-src_Notes.h,v 1.3 2014/03/12 12:28:28 wiz Exp $

Fix
cd src/ && /usr/bin/make -f Makefile all
/usr/pkg/qt4/bin/moc -DQT_NO_DEBUG -DQT_XML_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -I/usr/pkg/qt4/mkspecs/netbsd-g++ -I. -I/usr/pkg/qt4/include/QtCore -I/usr/pkg/qt4/include/QtNetwork -I/usr/pkg/qt4/include/QtGui -I/usr/pkg/qt4/include/QtXml -I/usr/pkg/qt4/include -I. -I. -I/usr/pkg/include CommonData.h -o moc_CommonData.cpp
usr/pkg/include/boost/type_traits/detail/has_binary_operator.hp:50: Parse error at "BOOST_JOIN"

using patch similar to one reported in
https://bugreports.qt-project.org/browse/QTBUG-22829

--- src/Notes.h.orig	2014-01-16 13:37:29.000000000 +0000
+++ src/Notes.h
@@ -33,7 +33,9 @@
 
 #include  "SerSupport.h"
 #include  <boost/serialization/split_member.hpp>
+#ifndef Q_MOC_RUN  // See: https://bugreports.qt-project.org/browse/QTBUG-22829
 #include  <boost/lexical_cast.hpp>
+#endif
 
 #ifdef ERR
 #undef ERR
