$NetBSD: patch-src_lib_synergy_unix_AppUtilUnix.cpp,v 1.1 2023/03/28 10:08:31 tnn Exp $

Fix use-after-free.
https://github.com/symless/synergy-core/pull/7208

--- src/lib/synergy/unix/AppUtilUnix.cpp.orig	2022-06-08 15:33:52.000000000 +0000
+++ src/lib/synergy/unix/AppUtilUnix.cpp
@@ -148,8 +148,8 @@ AppUtilUnix::getCurrentLanguageCode()
           groupStartI = strI + 1;
       }
 
-      XFree(kbdDescr);
       XkbFreeNames(kbdDescr, XkbSymbolsNameMask, true);
+      XFree(kbdDescr);
       XCloseDisplay(display);
 
       result = X11LayoutsParser::convertLayotToISO("/usr/share/X11/xkb/rules/evdev.xml", result);
