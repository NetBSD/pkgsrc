$NetBSD: patch-src_applications_differential_render_DifferentialChangesetRenderer.php,v 1.1 2017/03/17 21:16:38 roy Exp $

Leave tab stops alone.

--- src/applications/differential/render/DifferentialChangesetRenderer.php.orig	2017-03-17 19:59:28.971453778 +0000
+++ src/applications/differential/render/DifferentialChangesetRenderer.php
@@ -366,7 +366,7 @@ abstract class DifferentialChangesetRend
     // TODO: Let the user customize their tab width / display style.
     // TODO: We should possibly post-process "\r" as well.
     // TODO: Both these steps should happen earlier.
-    $result = str_replace("\t", '  ', $result);
+    // $result = str_replace("\t", '  ', $result);
 
     return phutil_safe_html($result);
   }
