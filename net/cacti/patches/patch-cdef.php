$NetBSD: patch-cdef.php,v 1.1 2014/08/23 12:50:25 adam Exp $

Fixes for:
CVE-2014-2326 Unspecified HTML Injection Vulnerability
CVE-2014-2328 Unspecified Remote Command Execution Vulnerability
CVE-2014-2708 Unspecified SQL Injection Vulnerability
CVE-2014-2709 Unspecified Remote Command Execution Vulnerability

--- cdef.php.orig	2013-08-06 22:31:19.000000000 -0400
+++ cdef.php		2014-04-04 21:39:04.000000000 -0400
@@ -431,7 +431,7 @@
 						<a class="linkEditMain" href="<?php print htmlspecialchars("cdef.php?action=item_edit&id=" . $cdef_item["id"] . "&cdef_id=" . $cdef["id"]);?>">Item #<?php print htmlspecialchars($i);?></a>
 					</td>
 					<td>
-						<em><?php $cdef_item_type = $cdef_item["type"]; print $cdef_item_types[$cdef_item_type];?></em>: <strong><?php print get_cdef_item_name($cdef_item["id"]);?></strong>
+						<em><?php $cdef_item_type = $cdef_item["type"]; print $cdef_item_types[$cdef_item_type];?></em>: <strong><?php print htmlspecialchars(get_cdef_item_name($cdef_item["id"]));?></strong>
 					</td>
 					<td>
 						<a href="<?php print htmlspecialchars("cdef.php?action=item_movedown&id=" . $cdef_item["id"] . "&cdef_id=" . $cdef["id"]);?>"><img src="images/move_down.gif" border="0" alt="Move Down"></a>
diff -ruBbd graph_xport.php graph_xport.php
