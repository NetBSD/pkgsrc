$NetBSD: patch-install_checkConfiguration.php,v 1.1 2025/03/03 15:21:05 manu Exp $

Fix webSiteRootURL if Apache Alias directive is used

When Apache Alias directive is used to map AVideo installation on
a given URL prefix, webSiteRootURL should be derived from the
CONTEXT_PREFIX environment variable

From upstream https://github.com/WWBN/AVideo/pull/9885

--- ./install/checkConfiguration.php.orig
+++ ./install/checkConfiguration.php
@@ -192,9 +192,14 @@
 \$global['disableTimeFix'] = 0;
 \$global['logfile'] = '{$_POST['systemRootPath']}videos/avideo.log';
 if(!empty(\$_SERVER['SERVER_NAME']) && \$_SERVER['SERVER_NAME']!=='localhost' && !filter_var(\$_SERVER['SERVER_NAME'], FILTER_VALIDATE_IP)) {
-    // get the subdirectory, if exists
-    \$file = str_replace(\"\\\\\", \"/\", __FILE__);
-    \$subDir = str_replace(array(\$_SERVER[\"DOCUMENT_ROOT\"], 'videos/configuration.php'), array('',''), \$file);
+    // get the subdirectory, through CONTEXT_PREFIX if Apache Alias
+    // directive is used, or from DOCUMENT_ROOT otherwise
+    if (!empty(\$_SERVER['CONTEXT_PREFIX'])) {
+        \$subDir = \$_SERVER['CONTEXT_PREFIX'];
+    } else {
+        \$file = str_replace(\"\\\\\", \"/\", __FILE__);
+        \$subDir = str_replace(array(\$_SERVER[\"DOCUMENT_ROOT\"], 'videos/configuration.php'), array('',''), \$file);
+    }
     \$global['webSiteRootURL'] = \"http\".(!empty(\$_SERVER['HTTPS'])?\"s\":\"\").\"://\".\$_SERVER['SERVER_NAME'].\$subDir;
 }else{
     \$global['webSiteRootURL'] = '{$_POST['webSiteRootURL']}';

