$NetBSD: patch-htdocs_add__value__form.php,v 1.1.2.2 2013/01/23 20:18:31 tron Exp $

* Fix XSS for CVE-2012-1114/CVE-2012-1115 from repository,
	74434e5ca3fb66018fad60766f833f15689fcbfc.

--- htdocs/add_value_form.php.orig	2011-10-27 02:07:09.000000000 +0000
+++ htdocs/add_value_form.php
@@ -34,7 +34,7 @@ if ($request['attribute']->isReadOnly())
 # Render the form
 if (! strcasecmp($request['attr'],'objectclass') || get_request('meth','REQUEST') != 'ajax') {
 	# Render the form.
-	$request['page']->drawTitle(sprintf('%s <b>%s</b> %s <b>%s</b>',_('Add new'),$request['attr'],_('value to'),get_rdn($request['dn'])));
+    $request['page']->drawTitle(sprintf(_('Add new <b>%s</b> value to <b>%s</b>'), htmlspecialchars($request['attr']),htmlspecialchars(get_rdn($request['dn']))));
 	$request['page']->drawSubTitle();
 
 	if (! strcasecmp($request['attr'],'objectclass')) {
