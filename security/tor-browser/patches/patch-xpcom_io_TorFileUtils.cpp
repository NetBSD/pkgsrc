$NetBSD: patch-xpcom_io_TorFileUtils.cpp,v 1.3 2020/04/28 19:38:49 wiz Exp $

Set default directory for configuration files and profiles to $HOME/.tor-browser

--- xpcom/io/TorFileUtils.cpp.orig	2019-02-23 20:01:00.000000000 +0000
+++ xpcom/io/TorFileUtils.cpp
@@ -20,7 +20,17 @@ TorBrowser_GetUserDataDir(nsIFile *aExeF
   NS_ENSURE_ARG_POINTER(aFile);
   nsCOMPtr<nsIFile> tbDataDir;
 
-#ifdef TOR_BROWSER_DATA_OUTSIDE_APP_DIR
+#if defined(TOR_BROWSER_DATA_IN_HOME_DIR)
+  const char *homeDir = getenv("HOME");
+  if (!homeDir || !*homeDir)
+    return NS_ERROR_FAILURE;
+  nsresult rv = NS_NewNativeLocalFile(nsDependentCString(homeDir), true,
+                                      getter_AddRefs(tbDataDir));
+  NS_ENSURE_SUCCESS(rv, rv);
+  nsAutoCString leafSubdir(NS_LITERAL_CSTRING(".tor-browser"));
+  rv = tbDataDir->AppendNative(leafSubdir);
+  NS_ENSURE_SUCCESS(rv, rv);
+#elif TOR_BROWSER_DATA_OUTSIDE_APP_DIR
   nsAutoCString tbDataLeafName(NS_LITERAL_CSTRING("TorBrowser-Data"));
   nsCOMPtr<nsIFile> appRootDir;
   nsresult rv = GetAppRootDir(aExeFile, getter_AddRefs(appRootDir));
