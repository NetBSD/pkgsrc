$NetBSD: patch-src_lib_random.cpp,v 1.1 2015/12/11 13:35:04 wiz Exp $

Add a bunch of missing includes hidden by libstdc++ namespace pollution.

--- src/lib/random.cpp.orig	2013-05-04 00:33:31.000000000 +0000
+++ src/lib/random.cpp
@@ -23,6 +23,7 @@
 
 #if defined(Q_WS_X11) || defined(Q_WS_MAC)
 	#include <QFile>
+	#include <unistd.h>
 #elif defined(Q_WS_WIN)
 	#include <windows.h>
 	#include <wincrypt.h>
