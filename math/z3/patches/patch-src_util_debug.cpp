$NetBSD: patch-src_util_debug.cpp,v 1.1 2016/07/16 04:02:13 markd Exp $

gcc6 fix

--- src/util/debug.cpp.orig	2015-10-05 12:07:19.000000000 +0000
+++ src/util/debug.cpp
@@ -76,7 +76,7 @@ void invoke_gdb() {
     for (;;) {
         std::cerr << "(C)ontinue, (A)bort, (S)top, (T)hrow exception, Invoke (G)DB\n";
         char result;
-        bool ok = (std::cin >> result);
+        bool ok = bool(std::cin >> result);
         if (!ok) exit(ERR_INTERNAL_FATAL); // happens if std::cin is eof or unattached.
         switch(result) {
         case 'C':
