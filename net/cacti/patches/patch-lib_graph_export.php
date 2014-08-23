$NetBSD: patch-lib_graph_export.php,v 1.1 2014/08/23 12:50:25 adam Exp $

Fixes for:
CVE-2014-2326 Unspecified HTML Injection Vulnerability
CVE-2014-2328 Unspecified Remote Command Execution Vulnerability
CVE-2014-2708 Unspecified SQL Injection Vulnerability
CVE-2014-2709 Unspecified Remote Command Execution Vulnerability

--- lib/graph_export.php.orig	2013-08-06 22:31:19.000000000 -0400
+++ lib/graph_export.php	2014-04-04 21:39:05.000000000 -0400
@@ -339,7 +339,7 @@
 	chdir($stExportDir);
 
 	/* set the initial command structure */
-	$stExecute = 'ncftpput -R -V -r 1 -u '.$aFtpExport['username'].' -p '.$aFtpExport['password'];
+	$stExecute = 'ncftpput -R -V -r 1 -u ' . cacti_escapeshellarg($aFtpExport['username']) . ' -p ' . cacti_escapeshellarg($aFtpExport['password']);
 
 	/* if the user requested passive mode, use it */
 	if ($aFtpExport['passive']) {
@@ -347,7 +347,7 @@
 	}
 
 	/* setup the port, server, remote directory and all files */
-	$stExecute .= ' -P ' . $aFtpExport['port'] . ' ' . $aFtpExport['server'] . ' ' . $aFtpExport['remotedir'] . ".";
+	$stExecute .= ' -P ' . cacti_escapeshellarg($aFtpExport['port']) . ' ' . cacti_escapeshellarg($aFtpExport['server']) . ' ' . cacti_escapeshellarg($aFtpExport['remotedir']) . ".";
 
 	/* run the command */
 	$iExecuteReturns = 0;
