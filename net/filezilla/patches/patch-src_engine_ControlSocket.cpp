$NetBSD: patch-src_engine_ControlSocket.cpp,v 1.1 2015/07/08 16:46:43 richard Exp $
upstream workaround for clash with 'struct mutex' on SunOS

--- src/engine/ControlSocket.cpp.orig	2015-03-28 04:30:03.000000000 +0000
+++ src/engine/ControlSocket.cpp
@@ -14,7 +14,9 @@
 #include <wx/filename.h>
 
 #ifndef __WXMSW__
+	#define mutex mutex_override // Sadly on some platforms system headers include conflicting names
 	#include <netdb.h>
+	#undef mutex
 	#ifndef AI_IDN
 		#include <idna.h>
 		extern "C" {
