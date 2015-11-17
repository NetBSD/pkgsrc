$NetBSD: patch-xbmc_interfaces_python_XBPython.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/interfaces/python/XBPython.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/interfaces/python/XBPython.cpp
@@ -475,7 +475,7 @@ void XBPython::Finalize()
 #if !(defined(TARGET_DARWIN) || defined(TARGET_WINDOWS))
     DllLoaderContainer::UnloadPythonDlls();
 #endif
-#if defined(TARGET_POSIX) && !defined(TARGET_DARWIN) && !defined(TARGET_FREEBSD)
+#if defined(TARGET_POSIX) && !defined(TARGET_DARWIN) && !defined(TARGET_FREEBSD) && !defined(TARGET_NETBSD)
     // we can't release it on windows, as this is done in UnloadPythonDlls() for win32 (see above).
     // The implementation for linux needs looking at - UnloadPythonDlls() currently only searches for "python26.dll"
     // The implementation for osx can never unload the python dylib.
