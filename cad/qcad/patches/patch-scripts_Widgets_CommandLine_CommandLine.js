$NetBSD: patch-scripts_Widgets_CommandLine_CommandLine.js,v 1.1 2019/07/31 19:30:21 plunky Exp $

handle system IDs for common systems

--- scripts/Widgets/CommandLine/CommandLine.js.orig	2019-03-05 22:23:06.533419113 +0000
+++ scripts/Widgets/CommandLine/CommandLine.js
@@ -448,6 +448,15 @@ CommandLine.init = function(basePath) {
     case "linux":
         system = "Linux";
         break;
+    case "netbsd":
+	system = "NetBSD";
+	break;
+    case "freebsd":
+	system = "FreeBSD";
+	break;
+    case "solaris":
+	system = "Solaris";
+	break;
     }
     EAction.handleUserMessage(
                 "%1 %2 / %3 %4"
