$NetBSD: patch-src_applications_diffusion_controller_DiffusionBrowseController.php,v 1.2 2017/03/18 13:48:48 roy Exp $

Leave tab stops alone.

--- src/applications/diffusion/controller/DiffusionBrowseController.php.orig	2017-03-16 16:52:01.000000000 +0000
+++ src/applications/diffusion/controller/DiffusionBrowseController.php
@@ -1289,7 +1289,7 @@ final class DiffusionBrowseController ex
           "\xE2\x80\x8B",
 
           // TODO: [HTML] Not ideal.
-          phutil_safe_html(str_replace("\t", '  ', $line['data'])),
+          phutil_safe_html($line['data']),
         ));
 
       if ($this->coverage) {
