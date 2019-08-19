$NetBSD: patch-lib_lib.pl,v 1.1 2019/08/19 05:59:56 gutteridge Exp $

Adjust indexing basis for compatibility with Perl >=5.30.

--- lib/lib.pl.orig	2011-06-01 15:40:47.000000000 +0000
+++ lib/lib.pl
@@ -1,6 +1,5 @@
 #!/usr/bin/perl
 
-$[ = 1;			# set array base to 1
 $, = ' ';		# set output field separator
 $\ = "\n";		# set output record separator
 
@@ -86,9 +85,9 @@ while (<>) {
 sub output {
     local($line) = @_;
     @line_fields = split(/\|/, $line, 9999);
-    $retval = $line_fields[1];
-    $feature = $line_fields[2];
-    $param_def = $line_fields[4];
+    $retval = $line_fields[0];
+    $feature = $line_fields[1];
+    $param_def = $line_fields[3];
 
     $orig = $feature;
     $feature =~ s/^@//;
@@ -106,16 +105,16 @@ sub output {
     }
 
     if ($param_def eq 'string') {
-	$call_param = ', ' . $line_fields[5];
+	$call_param = ', ' . $line_fields[4];
 	$param_buf = '';
 	$buf_set = '';
 	$param_decl = ",\n            " . $space . '    const char *' .
 
-	  $line_fields[5];
-	$send_ptr = "\n\tconst void *send_ptr = " . $line_fields[5] . ';';
+	  $line_fields[4];
+	$send_ptr = "\n\tconst void *send_ptr = " . $line_fields[4] . ';';
 	$send_size = "\n\tconst size_t send_size =\n\t\tstrlen (" .
 
-	  $line_fields[5] . ') + 1;';
+	  $line_fields[4] . ') + 1;';
     }
     else {
 	$call_param = '';
@@ -128,7 +127,7 @@ sub output {
 	if ($nr_params) {
 	    $param_buf = "\n\tstruct {\n";
 	}
-	for ($param = 1; $param <= $nr_params; $param++) {
+	for ($param = 0; $param < $nr_params; $param++) {
 	    $list = $params[$param];
 	    $type = $params[$param];
 	    $type =~ s/\(.*//;
@@ -137,13 +136,13 @@ sub output {
 	    $count = (@fields = split(/,/, $list, 9999));
 
 	    if ($count > 0) {
-		for ($field = 1; $field <= $count; $field++) {
+		for ($field = 0; $field < $count; $field++) {
 		    $param_buf .= "\t\t$convert{$type} buf_$fields[$field];\n";
 		    $buf_set .= "\tparam_buf.buf_$fields[$field] = $fields[$field];\n";
 		}
 	    }
 
-	    for ($field = 1; $field <= $count; $field++) {
+	    for ($field = 0; $field < $count; $field++) {
 		if ($param_decl eq '') {
 		    $param_decl = ",\n            " . $space . '    ';
 		}
