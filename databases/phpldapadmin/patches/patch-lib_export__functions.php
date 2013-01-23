$NetBSD: patch-lib_export__functions.php,v 1.1.2.2 2013/01/23 20:18:31 tron Exp $

* Fix XSS for CVE-2012-1114/CVE-2012-1115 from repository,
	74434e5ca3fb66018fad60766f833f15689fcbfc.

--- lib/export_functions.php.orig	2011-10-27 02:07:09.000000000 +0000
+++ lib/export_functions.php
@@ -324,9 +324,9 @@ class ExportCSV extends Export {
 		}
 
 		if ($this->compress)
-			echo gzencode($output);
+			return gzencode($output);
 		else
-			echo $output;
+			return $output;
 	}
 
 	/**
@@ -428,9 +428,9 @@ class ExportDSML extends Export {
 		$output .= sprintf('</dsml>%s',$this->br);
 
 		if ($this->compress)
-			echo gzencode($output);
+			return gzencode($output);
 		else
-			echo $output;
+			return $output;
 	}
 }
 
@@ -506,9 +506,9 @@ class ExportLDIF extends Export {
 		}
 
 		if ($this->compress)
-			echo gzencode($output);
+			return gzencode($output);
 		else
-			echo $output;
+			return $output;
 	}
 
 	/**
@@ -633,9 +633,9 @@ class ExportVCARD extends Export {
 		}
 
 		if ($this->compress)
-			echo gzencode($output);
+			return gzencode($output);
 		else
-			echo $output;
+			return $output;
 	}
 }
 ?>
