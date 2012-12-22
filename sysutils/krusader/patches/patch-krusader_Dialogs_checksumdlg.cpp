$NetBSD: patch-krusader_Dialogs_checksumdlg.cpp,v 1.1 2012/12/22 02:31:33 joerg Exp $

--- krusader/Dialogs/checksumdlg.cpp.orig	2012-12-22 01:03:14.000000000 +0000
+++ krusader/Dialogs/checksumdlg.cpp
@@ -26,7 +26,7 @@
 class CS_Tool; // forward
 typedef void PREPARE_PROC_FUNC(KProcess& proc, CS_Tool *self, const QStringList& files, 
 	const QString checksumFile, bool recursive, const QString& stdoutFileName, 
-	const QString& stderrFileName,	const QString& type=QString::null);
+	const QString& stderrFileName,	const QString& type);
 typedef QStringList GET_FAILED_FUNC(const QStringList& stdOut, const QStringList& stdErr);
 
 class CS_Tool {
