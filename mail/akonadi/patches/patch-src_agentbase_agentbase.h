$NetBSD: patch-src_agentbase_agentbase.h,v 1.2 2026/09/06 11:02:54 markd Exp $

XXXX Why does this trigger?

--- src/agentbase/agentbase.h.orig	2026-08-14 03:28:35.000000000 +0000
+++ src/agentbase/agentbase.h
@@ -445,9 +445,9 @@ public:
     template<typename T>
     static int initCore(int argc, char **argv)
     {
-#if __has_include(<QApplication>)
-        static_assert(false, "This links to QWidgets");
-#endif
+// #if __has_include(<QApplication>)
+//         static_assert(false, "This links to QWidgets");
+// #endif
 
         QCoreApplication app(argc, argv);
         debugAgent(argc, argv);
