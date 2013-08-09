$NetBSD: patch-src_main.cpp,v 1.2 2013/08/09 11:47:57 drochner Exp $

--- src/main.cpp.orig	2013-08-04 06:20:27.000000000 +0000
+++ src/main.cpp
@@ -41,6 +41,7 @@
 	#pragma comment(lib,"Winmm.lib")
 #endif
 #endif //Q_OS_WIN
+#include <clocale>
 
 //! @class GettextStelTranslator
 //! Provides i18n support through gettext.
