$NetBSD: patch-installer_config.php,v 1.1 2013/06/15 16:08:09 taca Exp $

Fix from repository:
* commit 70ef48c2f311f1773a4b4deb8fcffd8ea72326f9:
  Remove old enable_caching option from Installer

--- installer/config.php.orig	2013-05-16 18:06:35.000000000 +0000
+++ installer/config.php
@@ -15,7 +15,6 @@ $RCI->load_defaults();
 // register these boolean fields
 $RCI->bool_config_props = array(
   'ip_check' => 1,
-  'enable_caching' => 1,
   'enable_spellcheck' => 1,
   'auto_create_user' => 1,
   'smtp_log' => 1,
@@ -127,16 +126,6 @@ echo $check_ipcheck->show(intval($RCI->g
 <p class="hint">This increases security but can cause sudden logouts when someone uses a proxy with changing IPs.</p>
 </dd>
 
-<dt class="propname">enable_caching</dt>
-<dd>
-<?php
-
-$check_caching = new html_checkbox(array('name' => '_enable_caching', 'id' => "cfgcache"));
-echo $check_caching->show(intval($RCI->getprop('enable_caching')), array('value' => 1));
-
-?>
-<label for="cfgcache">Cache messages in local database</label><br />
-</dd>
 
 <dt class="propname">enable_spellcheck</dt>
 <dd>
