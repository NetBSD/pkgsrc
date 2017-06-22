$NetBSD: patch-qemu-xen_scripts_texi2pod.pl,v 1.1 2017/06/22 16:09:17 joerg Exp $

--- qemu-xen/scripts/texi2pod.pl.orig	2017-06-19 15:07:47.531845451 +0000
+++ qemu-xen/scripts/texi2pod.pl
@@ -310,7 +310,7 @@ while(<$inf>) {
 	@columns = ();
 	for $column (split (/\s*\@tab\s*/, $1)) {
 	    # @strong{...} is used a @headitem work-alike
-	    $column =~ s/^\@strong{(.*)}$/$1/;
+	    $column =~ s/^\@strong\{(.*)\}$/$1/;
 	    push @columns, $column;
 	}
 	$_ = "\n=item ".join (" : ", @columns)."\n";
