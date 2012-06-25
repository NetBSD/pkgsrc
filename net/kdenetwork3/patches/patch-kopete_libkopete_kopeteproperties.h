$NetBSD: patch-kopete_libkopete_kopeteproperties.h,v 1.1 2012/06/25 11:51:01 joerg Exp $

--- kopete/libkopete/kopeteproperties.h.orig	2012-06-18 21:53:12.000000000 +0000
+++ kopete/libkopete/kopeteproperties.h
@@ -18,11 +18,11 @@
 #define KOPETEPROPERTIES_H
 
 #include <qasciidict.h>
+#include <qvariant.h>
 
 #include <typeinfo>
 
 class QString;
-class QVariant;
 class QDomElement;
 
 namespace Kopete
