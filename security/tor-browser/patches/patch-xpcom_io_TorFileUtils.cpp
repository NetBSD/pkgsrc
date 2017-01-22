$NetBSD: patch-xpcom_io_TorFileUtils.cpp,v 1.1 2017/01/22 12:27:22 ryoon Exp $

--- xpcom/io/TorFileUtils.cpp.orig	2016-12-10 08:02:57.000000000 +0000
+++ xpcom/io/TorFileUtils.cpp
@@ -15,7 +15,17 @@ TorBrowser_GetUserDataDir(nsIFile *aExeF
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
+  nsAutoCString leafSubdir(NS_LITERAL_CSTRING("TorBrowser-Data"));
+  rv = tbDataDir->AppendNative(leafSubdir);
+  NS_ENSURE_SUCCESS(rv, rv);
+#elif defined(TOR_BROWSER_DATA_OUTSIDE_APP_DIR)
   nsAutoCString tbDataLeafName(NS_LITERAL_CSTRING("TorBrowser-Data"));
   nsCOMPtr<nsIFile> appRootDir;
   nsresult rv = GetAppRootDir(aExeFile, getter_AddRefs(appRootDir));
