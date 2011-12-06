$NetBSD: patch-scribus_cupsoptions.cpp,v 1.1 2011/12/06 19:49:54 joerg Exp $

--- scribus/cupsoptions.cpp.orig	2011-12-06 14:32:35.000000000 +0000
+++ scribus/cupsoptions.cpp
@@ -33,6 +33,7 @@ for which a new license (GPL+exception) 
 #include <qstringlist.h>
 #ifdef HAVE_CUPS
 #include <cups/cups.h>
+#include <cups/ppd.h>
 #endif
 #include <qtooltip.h>
 extern QPixmap loadIcon(QString nam);
