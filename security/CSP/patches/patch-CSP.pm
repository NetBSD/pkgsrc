$NetBSD: patch-CSP.pm,v 1.1 2018/02/26 12:32:41 triaxx Exp $

Fix unescaped braces deprecated since perl 5.22.

--- CSP.pm.orig	2007-03-10 22:28:53.000000000 +0000
+++ CSP.pm
@@ -111,7 +111,7 @@ sub _rewrite
     my $vars = shift;
     my $line = shift;
 
-    while ($line =~ s/%{([a-zA-Z0-9_\.]+)}/$vars->{$1}/eg) { }
+    while ($line =~ s/%\{([a-zA-Z0-9_\.]+)\}/$vars->{$1}/eg) { }
     $line;
   }
 
@@ -150,7 +150,7 @@ sub mppFile
 	      {
 		my $expr = $1;
 		
-		$expr =~ s/%{([A-Za-z0-9_\.]+)}/"\$vars->{\"$1\"}"/eg;
+		$expr =~ s/%\{([A-Za-z0-9_\.]+)\}/"\$vars->{\"$1\"}"/eg;
 		
 		my $result = eval $expr;
 		$self->die("$@") if $@;
