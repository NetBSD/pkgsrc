$NetBSD: patch-guiserver_guiserver.lsp,v 1.1 2014/07/07 14:25:31 ryoon Exp $

--- guiserver/guiserver.lsp.orig	2014-04-08 14:02:28.000000000 +0000
+++ guiserver/guiserver.lsp
@@ -1879,7 +1879,7 @@ true
 			(env "JAVA_HOME")
 			(process (string (env "JAVA_HOME") "/bin/java -jar " server-path " " portIn))
 
-			(process (string "/usr/bin/java -jar " server-path " " portIn))
+			(process (string "@JAVA_HOME@/bin/java -jar " server-path " " portIn))
 
 		)
 	)
