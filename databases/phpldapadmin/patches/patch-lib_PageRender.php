$NetBSD: patch-lib_PageRender.php,v 1.2 2022/04/16 03:11:28 khorben Exp $

Fix for PHP >= 5.5

--- lib/PageRender.php.orig	2022-04-15 22:45:43.000000000 +0000
+++ lib/PageRender.php
@@ -827,7 +827,7 @@ class PageRender extends Visitor {
 		if (! $attribute->getOldValue($i))
 			return;
 
-		draw_jpeg_photo($this->getServer(),$this->template->getDN(),$attribute->getName(),$i,false,false);
+		draw_jpeg_photo($this->getServer(),$this->template->getDN(),$i,$attribute->getName(),false,false);
 	}
 
 	/**
@@ -844,16 +844,16 @@ class PageRender extends Visitor {
 		# If the attribute is modified, the new value needs to be stored in a session variable for the draw_jpeg_photo callback.
 		if ($attribute->hasBeenModified()) {
 			$_SESSION['tmp'][$attribute->getName()][$i] = $attribute->getValue($i);
-			draw_jpeg_photo(null,$this->template->getDN(),$attribute->getName(),$i,false,false);
+			draw_jpeg_photo(null,$this->template->getDN(),$i,$attribute->getName(),false,false);
 		} else
-			draw_jpeg_photo($this->getServer(),$this->template->getDN(),$attribute->getName(),$i,false,false);
+			draw_jpeg_photo($this->getServer(),$this->template->getDN(),$i,$attribute->getName(),false,false);
 	}
 
 	protected function drawFormReadOnlyValueJpegAttribute($attribute,$i) {
 		$this->draw('HiddenValue',$attribute,$i);
 		$_SESSION['tmp'][$attribute->getName()][$i] = $attribute->getValue($i);
 
-		draw_jpeg_photo(null,$this->template->getDN(),$attribute->getName(),$i,false,false);
+		draw_jpeg_photo(null,$this->template->getDN(),$i,$attribute->getName(),false,false);
 	}
 
 	protected function drawFormReadOnlyValueMultiLineAttribute($attribute,$i) {
