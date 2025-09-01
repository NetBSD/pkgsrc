$NetBSD: patch-src_AudacityApp.cpp,v 1.1 2025/09/01 15:12:19 kikadf Exp $

* Fix CVE-2020-11867, https://github.com/audacity/audacity/commit/8bb55b8bbf0f0030224d0bfa1b290c4bc1d91b6a

--- src/AudacityApp.cpp.orig	2025-09-01 16:24:41.676126412 +0200
+++ src/AudacityApp.cpp
@@ -1786,7 +1786,7 @@ bool AudacityApp::InitTempDir()
    // The permissions don't always seem to be set on
    // some platforms.  Hopefully this fixes it...
    #ifdef __UNIX__
-   chmod(OSFILENAME(temp), 0755);
+   chmod(OSFILENAME(temp), 0700);
    #endif
 
    bool bSuccess = gPrefs->Write(wxT("/Directories/TempDir"), temp) && gPrefs->Flush();
