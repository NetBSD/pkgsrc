$NetBSD: patch-kget_ui_metalinkcreator_metalinker.cpp,v 1.1 2011/05/07 22:25:09 markd Exp $

http://secunia.com/advisories/44124/

--- kget/ui/metalinkcreator/metalinker.cpp	2011/04/09 09:24:33	1227468
+++ kget/ui/metalinkcreator/metalinker.cpp	2011/04/09 09:25:23	1227469
@@ -583,7 +583,13 @@
         return false;
     }
 
-    if (name.contains(QRegExp("$(\\.\\.?)?/")) || name.contains("/../") || name.endsWith("/..")) {
+    if (name.endsWith('/')) {
+        kError(5001) << "Name attribute of Metalink::File does not contain a file name:" << name;
+        return false;
+    }
+
+    const QStringList components = name.split('/');
+    if (name.startsWith('/') || components.contains("..") || components.contains(".")) {
         kError(5001) << "Name attribute of Metalink::File contains directory traversal directives:" << name;
         return false;
     }
