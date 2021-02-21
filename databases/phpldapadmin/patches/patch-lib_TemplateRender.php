$NetBSD: patch-lib_TemplateRender.php,v 1.1 2021/02/21 22:22:22 khorben Exp $

Fix for PHP >= 5.5

--- lib/TemplateRender.php.orig	2012-10-01 06:54:14.000000000 +0000
+++ lib/TemplateRender.php
@@ -2466,7 +2466,7 @@ function deleteAttribute(attrName,friend
 		if ($val = $attribute->getValue($i))
 			$default = get_enc_type($val);
 		else
-			$default = $this->getServer()->getValue('appearance','password_hash');
+			$default = $this->getServer()->getValue('appearance','pla_password_hash');
 
 		if (! $attribute->getPostValue())
 			printf('<input type="hidden" name="post_value[%s][]" value="%s" />',$attribute->getName(),$i);
