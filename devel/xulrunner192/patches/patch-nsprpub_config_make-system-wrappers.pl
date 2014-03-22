$NetBSD: patch-nsprpub_config_make-system-wrappers.pl,v 1.1 2014/03/22 18:02:14 gdt Exp $

--- ./nsprpub/config/make-system-wrappers.pl.orig	2012-03-06 14:45:41.000000000 +0000
+++ ./nsprpub/config/make-system-wrappers.pl
@@ -52,7 +52,12 @@ while (<STDIN>) {
     open OUT, ">$output_dir/$_";
     print OUT "#pragma GCC system_header\n";  # suppress include_next warning
     print OUT "#pragma GCC visibility push(default)\n";
-    print OUT "#include_next \<$_\>\n";
+	if ($_ =~ "freetype/tttables.h") {
+    	print OUT "#include \<ft2build.h\>\n";
+    	print OUT "#include_next FT_TRUETYPE_TABLES_H\n";
+	} else {
+    	print OUT "#include_next \<$_\>\n";
+	}
     print OUT "#pragma GCC visibility pop\n";
     close OUT;
 }
