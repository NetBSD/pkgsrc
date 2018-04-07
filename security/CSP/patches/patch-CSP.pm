$NetBSD: patch-CSP.pm,v 1.2 2018/04/07 10:53:34 triaxx Exp $

Fix unescaped braces deprecated since perl 5.22.

--- CSP.pm.orig	2007-03-10 22:28:53.000000000 +0000
+++ CSP.pm
@@ -50,7 +50,7 @@ sub new
 
     my $me = bless { dir=>$dir,name=>$name },$class;
 
-    open ALIASES,"$dir/etc/aliases.txt";
+    open ALIASES,"$dir/aliases.txt";
     while (<ALIASES>)
       {
 	chomp;
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
@@ -210,7 +210,7 @@ EOW
 	
 	## Default section
 	$cf->print("[ oids ]\n");
-	$self->addFile($cf,"$self->{dir}/etc/oids.conf");
+	$self->addFile($cf,"$self->{dir}/oids.conf");
 	
 	$cf->print("\n[ csp ]\n\n");
 	my ($k,$v);
@@ -288,7 +288,7 @@ EOC
 	    if ($name)
 	      {
 		my $econf = "$self->{dir}/csp/$name/extensions.conf";
-		$econf = "$self->{dir}/etc/extensions.conf" unless -f $econf;
+		$econf = "$self->{dir}/extensions.conf" unless -f $econf;
 		
 		$self->mppFile($cf,$args,$econf);
 	      }
@@ -296,7 +296,7 @@ EOC
 	    if ($name)
 	      {
 		my $econf = "$self->{dir}/csp/$name/crl_extensions.conf";
-		$econf = "$self->{dir}/etc/crl_extensions.conf" unless -f $econf;
+		$econf = "$self->{dir}/crl_extensions.conf" unless -f $econf;
 		
 		$self->mppFile($cf,$args,$econf);
 	      }
@@ -348,9 +348,9 @@ sub createFiles
 
     mkdir "$dir/private",00700;
     mkdir "$dir/private/keys",00700;
-    system('cp','-p',"$self->{dir}/etc/extensions.conf","$dir/extensions.conf");
-    system('cp','-p',"$self->{dir}/etc/crl_extensions.conf","$dir/crl_extensions.conf");
-    system('cp','-rp',"$self->{dir}/etc/public_html","$dir/");
+    system('cp','-p',"$self->{dir}/extensions.conf","$dir/extensions.conf");
+    system('cp','-p',"$self->{dir}/crl_extensions.conf","$dir/crl_extensions.conf");
+    system('cp','-rp',"$self->{dir}/public_html","$dir/");
   }
 
 sub caDir
