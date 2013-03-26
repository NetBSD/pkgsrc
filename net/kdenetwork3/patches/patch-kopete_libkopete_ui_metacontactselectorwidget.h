$NetBSD: patch-kopete_libkopete_ui_metacontactselectorwidget.h,v 1.1 2013/03/26 23:30:46 joerg Exp $

--- kopete/libkopete/ui/metacontactselectorwidget.h.orig	2013-03-26 19:40:25.000000000 +0000
+++ kopete/libkopete/ui/metacontactselectorwidget.h
@@ -23,10 +23,10 @@
 #include "kopetelistviewitem.h"
 #include "kopete_export.h"
 
-class Kopete::MetaContact;
-
 namespace Kopete
 {
+    class MetaContact;
+
 namespace UI
 {
 
