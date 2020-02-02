$NetBSD: patch-src_lib_jupyterutils.cpp,v 1.1 2020/02/02 02:53:53 markd Exp $

--- src/lib/jupyterutils.cpp.orig	2020-01-06 13:49:54.000000000 +0000
+++ src/lib/jupyterutils.cpp
@@ -219,7 +219,7 @@ std::tuple<int, int> JupyterUtils::getNb
     int nbformatMajor = notebook.value(nbformatKey).toInt();
     int nbformatMinor = notebook.value(nbformatMinorKey).toInt();
 
-    return {nbformatMajor, nbformatMinor};
+    return std::make_tuple(nbformatMajor, nbformatMinor);
 }
 
 QString JupyterUtils::getCellType(const QJsonObject& cell)
