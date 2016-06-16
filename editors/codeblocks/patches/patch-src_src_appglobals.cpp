$NetBSD: patch-src_src_appglobals.cpp,v 1.1 2016/06/16 02:28:51 kamil Exp $

Detect NetBSD as NetBSD.

--- src/src/appglobals.cpp.orig	2016-01-23 16:43:03.000000000 +0000
+++ src/src/appglobals.cpp
@@ -49,6 +49,8 @@ namespace appglobals
     const wxString AppPlatform           = _T("Darwin");
 #elif defined(__FreeBSD__)
     const wxString AppPlatform           = _T("FreeBSD");
+#elif defined(__NetBSD__)
+    const wxString AppPlatform           = _T("NetBSD");
 #elif defined(__UNIX__)
     const wxString AppPlatform           = _T("Linux");
 #else
