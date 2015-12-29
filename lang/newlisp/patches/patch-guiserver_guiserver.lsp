$NetBSD: patch-guiserver_guiserver.lsp,v 1.2 2015/12/29 23:34:52 dholland Exp $

Don't hardwire paths.

--- guiserver/guiserver.lsp.orig	2014-04-08 14:02:28.000000000 +0000
+++ guiserver/guiserver.lsp
@@ -1879,7 +1879,7 @@ true
 			(env "JAVA_HOME")
 			(process (string (env "JAVA_HOME") "/bin/java -jar " server-path " " portIn))
 
-			(process (string "/usr/bin/java -jar " server-path " " portIn))
+			(process (string "@JAVA_HOME@/bin/java -jar " server-path " " portIn))
 
 		)
 	)
