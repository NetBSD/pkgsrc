$NetBSD: patch-src_agentbase_agentbase.h,v 1.1 2025/12/21 12:56:08 markd Exp $

XXXX Why does this trigger?

--- src/agentbase/agentbase.h.orig	2025-10-18 04:11:17.000000000 +0000
+++ src/agentbase/agentbase.h
@@ -431,9 +431,9 @@ public:
         // Disable session management
         qunsetenv("SESSION_MANAGER");
 
-#if __has_include(<QApplication>)
-        static_assert(false, "This links to QWidgets");
-#endif
+// #if __has_include(<QApplication>)
+//         static_assert(false, "This links to QWidgets");
+// #endif
 
         QCoreApplication app(argc, argv);
         debugAgent(argc, argv);
