$NetBSD: patch-toolkit_xre_nsXREDirProvider.cpp,v 1.2 2016/03/20 06:53:37 ryoon Exp $

https://github.com/torbsd/openbsd-ports/blob/beeb760037237c6e1864942356b8135e9c430d78/www/tbb/tor-browser/patches/patch-toolkit_xre_nsXREDirProvider_cpp

--- toolkit/xre/nsXREDirProvider.cpp.orig	2016-03-19 23:19:47.000000000 +0000
+++ toolkit/xre/nsXREDirProvider.cpp
@@ -1222,15 +1222,22 @@ nsXREDirProvider::GetUserDataDirectoryHo
   NS_ENSURE_ARG_POINTER(aFile);
   nsCOMPtr<nsIFile> localDir;
 
+#if 0
   nsresult rv = GetAppRootDir(getter_AddRefs(localDir));
   NS_ENSURE_SUCCESS(rv, rv);
   rv = localDir->AppendRelativeNativePath(NS_LITERAL_CSTRING("TorBrowser"
                                      XPCOM_FILE_PATH_SEPARATOR "Data"
                                      XPCOM_FILE_PATH_SEPARATOR "Browser"));
   NS_ENSURE_SUCCESS(rv, rv);
+#else
+  nsresult rv =
+    NS_NewNativeLocalFile(nsDependentCString(PR_GetEnv("HOME")), true,
+                          getter_AddRefs(localDir));
+  NS_ENSURE_SUCCESS(rv, rv);
+#endif
 
   if (aLocal) {
-    rv = localDir->AppendNative(NS_LITERAL_CSTRING("Caches"));
+    rv = localDir->AppendNative(NS_LITERAL_CSTRING(".tor-browser-caches"));
     NS_ENSURE_SUCCESS(rv, rv);
   }
 
@@ -1338,6 +1345,7 @@ nsXREDirProvider::GetAppRootDir(nsIFile*
   nsresult rv = GetAppDir()->Clone(getter_AddRefs(appRootDir));
   NS_ENSURE_SUCCESS(rv, rv);
 
+#if 0
   int levelsToRemove = 1; // In FF21+, appDir points to browser subdirectory.
 #if defined(XP_MACOSX)
   levelsToRemove += 2;
@@ -1358,6 +1366,7 @@ nsXREDirProvider::GetAppRootDir(nsIFile*
     if (didRemove)
       --levelsToRemove;
   }
+#endif
 
   if (!appRootDir)
     return NS_ERROR_FAILURE;
@@ -1454,7 +1463,7 @@ nsXREDirProvider::AppendSysUserExtension
 
 #elif defined(XP_UNIX)
 
-  static const char* const sXR = ".mozilla";
+  static const char* const sXR = ".tor-browser";
   rv = aFile->AppendNative(nsDependentCString(sXR));
   NS_ENSURE_SUCCESS(rv, rv);
 
@@ -1513,6 +1522,9 @@ nsXREDirProvider::AppendProfilePath(nsIF
   rv = aFile->AppendNative(nsDependentCString("mozilla"));
   NS_ENSURE_SUCCESS(rv, rv);
 #elif defined(XP_UNIX)
+  nsAutoCString folder;
+  if (!aLocal)
+    folder.Assign('.');
   if (!profile.IsEmpty()) {
     // Skip any leading path characters
     const char* profileStart = profile.get();
@@ -1521,17 +1533,23 @@ nsXREDirProvider::AppendProfilePath(nsIF
 
     // On the off chance that someone wanted their folder to be hidden don't
     // let it become ".."
-    if (*profileStart == '.')
+    if (*profileStart == '.' && !aLocal)
       profileStart++;
 
+#if 0
     // Make it hidden (by starting with ".").
     nsAutoCString folder(".");
+#endif
     folder.Append(profileStart);
     ToLowerCase(folder);
 
     rv = AppendProfileString(aFile, folder.BeginReading());
-    NS_ENSURE_SUCCESS(rv, rv);
+  } else {
+    folder.Append("tor-browser");
+    ToLowerCase(folder);
+    rv = aFile->AppendNative(folder);
   }
+  NS_ENSURE_SUCCESS(rv, rv);
 
 #else
 #error "Don't know how to get profile path on your platform"
