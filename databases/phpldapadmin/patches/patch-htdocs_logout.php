$NetBSD: patch-htdocs_logout.php,v 1.1.2.2 2013/01/23 20:18:31 tron Exp $

o Unset $_SESSION['ACTIVITY'] on logout from repository,
	88d41216f957f98bb0a22b1af779df964580fd5c.

--- htdocs/logout.php.orig	2011-10-27 02:07:09.000000000 +0000
+++ htdocs/logout.php
@@ -11,13 +11,16 @@
 
 require './common.php';
 
-if ($app['server']->logout())
+if ($app['server']->logout()) {
+	unset($_SESSION['ACTIVITY'][$app['server']->getIndex()]);
+
 	system_message(array(
-		'title'=>_('Authenticate to server'),
+		'title'=>_('Logout from Server'),
 		'body'=>_('Successfully logged out of server.'),
 		'type'=>'info'),
 		sprintf('index.php?server_id=%s',$app['server']->getIndex()));
-else
+
+} else
 	system_message(array(
 		'title'=>_('Failed to Logout of server'),
 		'body'=>_('Please report this error to the admins.'),
