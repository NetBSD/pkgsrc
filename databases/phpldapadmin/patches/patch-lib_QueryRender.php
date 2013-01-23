$NetBSD: patch-lib_QueryRender.php,v 1.2.2.2 2013/01/23 20:18:31 tron Exp $

o Fix XSS in query from repository, 7dc8d57d6952fe681cb9e8818df7f103220457bd.
  CVE-2012-0834

--- lib/QueryRender.php.orig	2011-10-27 02:07:09.000000000 +0000
+++ lib/QueryRender.php
@@ -497,7 +497,7 @@ class QueryRender extends PageRender {
 				$this->getAjaxRef($base),
 				$this->getAjaxRef($base),
 				($show == $this->getAjaxRef($base) ? '#F0F0F0' : '#E0E0E0'),
-				$base);
+                   htmlspecialchars($base));
 		}
 		echo '</tr>';
 		echo '</table>';
@@ -545,7 +545,7 @@ class QueryRender extends PageRender {
 		echo ' ]</small>';
 
 		echo '<br />';
-		printf('<small>%s: <b>%s</b></small>',_('Base DN'),$base);
+		printf('<small>%s: <b>%s</b></small>',_('Base DN'), htmlspecialchars($base));
 
 		echo '<br />';
 		printf('<small>%s: <b>%s</b></small>',_('Filter performed'),htmlspecialchars($this->template->resultsdata[$base]['filter']));
