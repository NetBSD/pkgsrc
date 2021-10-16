$NetBSD: patch-lib_DBD_File.pm,v 1.1.2.2 2021/10/16 17:51:39 tm Exp $

Fix CVE-2014-10402
https://github.com/perl5-dbi/dbi/pull/93/commits/19d0fb169eed475e1c053e99036b8668625cfa94

--- lib/DBD/File.pm.orig	2016-11-09 10:11:37.000000000 +0000
+++ lib/DBD/File.pm
@@ -109,7 +109,11 @@ sub connect
     # We do not (yet) care about conflicting attributes here
     # my $dbh = DBI->connect ("dbi:CSV:f_dir=test", undef, undef, { f_dir => "text" });
     # will test here that both test and text should exist
-    if (my $attr_hash = (DBI->parse_dsn ($dbname))[3]) {
+    #
+    # Parsing on our own similar to parse_dsn to find attributes in 'dbname' parameter.
+    if ($dbname) {
+	my @attrs = split /;/ => $dbname;
+	my $attr_hash = { map { split /\s*=>?\s*|\s*,\s*/, $_} @attrs };
 	if (defined $attr_hash->{f_dir} && ! -d $attr_hash->{f_dir}) {
 	    my $msg = "No such directory '$attr_hash->{f_dir}";
 	    $drh->set_err (2, $msg);
@@ -120,7 +124,6 @@ sub connect
     if ($attr and defined $attr->{f_dir} && ! -d $attr->{f_dir}) {
 	my $msg = "No such directory '$attr->{f_dir}";
 	$drh->set_err (2, $msg);
-	$attr->{RaiseError} and croak $msg;
 	return;
 	}
 
