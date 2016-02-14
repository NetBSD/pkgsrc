$NetBSD: patch-xpcom_io_nsAppFileLocationProvider.cpp,v 1.1 2016/02/14 07:30:54 ryoon Exp $

https://github.com/torbsd/openbsd-ports/blob/6bce5893badd924a4090fffa1998220505520661/www/tbb/tor-browser/patches/patch-xpcom_io_nsAppFileLocationProvider_cpp

--- xpcom/io/nsAppFileLocationProvider.cpp.orig	2016-02-13 07:06:53.000000000 +0000
+++ xpcom/io/nsAppFileLocationProvider.cpp
@@ -295,6 +295,7 @@ nsAppFileLocationProvider::GetProductDir
   bool exists;
   nsCOMPtr<nsIFile> localDir;
 
+#if 0
   rv = CloneMozBinDirectory(getter_AddRefs(localDir));
   NS_ENSURE_SUCCESS(rv, rv);
 
@@ -328,6 +329,12 @@ nsAppFileLocationProvider::GetProductDir
                                         XPCOM_FILE_PATH_SEPARATOR "Data"
                                         XPCOM_FILE_PATH_SEPARATOR "Browser"));
   NS_ENSURE_SUCCESS(rv, rv);
+#endif
+  rv = NS_NewNativeLocalFile(nsDependentCString(PR_GetEnv("HOME")), true, getter_AddRefs(localDir));
+  if (NS_FAILED(rv)) return rv;
+
+  rv = localDir->AppendRelativeNativePath(DEFAULT_PRODUCT_DIR);
+  if (NS_FAILED(rv)) return rv;
 
   if (aLocal) {
     rv = localDir->AppendNative(NS_LITERAL_CSTRING("Caches"));
