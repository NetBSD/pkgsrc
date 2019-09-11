$NetBSD: patch-src_e__commands.cc,v 1.1 2019/09/11 16:26:17 micha Exp $

Show error message if function fl_open_uri() fails.

--- src/e_commands.cc.orig	2018-08-03 04:22:13.000000000 +0000
+++ src/e_commands.cc
@@ -1180,7 +1180,13 @@ void CMD_LogViewer()
 
 void CMD_OnlineDocs()
 {
-	fl_open_uri("http://eureka-editor.sourceforge.net/?n=Docs.Index");
+	int rv;
+
+	rv = fl_open_uri("http://eureka-editor.sourceforge.net/?n=Docs.Index");
+	if (1 != rv)
+	{
+		Beep("Failed to open WWW browser");
+	}
 }
 
 
