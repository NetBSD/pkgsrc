$NetBSD: patch-dirvish.pl,v 1.1 2024/06/27 17:40:34 abs Exp $

Taken from debian - add per vault lockfile to stop overlapping runs

Taken from debian - From: Paul Slootman <paul@debian.org>
# If you do "dirvish --init" and forget the --vault bit, the error message
# is "vault undefined", which could make you think that a config file is
# incorrect. Change the message to "vault not specified", which is a bit
# clearer.

Taken from debian - From: Paul Slootman <paul@debian.org>
# If client is listed as the same as `hostname`, dirvish will not use
# ssh to connect but do a local transfer. Do the same if client is
# specified as 'localhost'.

--- dirvish.pl.orig	2024-06-20 09:31:29.558321590 +0000
+++ dirvish.pl
@@ -273,6 +273,13 @@ $$Options{vault} =~ /:/
 	and ($$Options{vault}, $$Options{branch})
 		= split(/:/, $Options{vault});
 
+# PS 20080819 the message "vault undefined" doesn't clearly say it's a command line problem
+for $key (qw(vault))
+{
+	length($$Options{$key}) or usage("$key not specified");
+	ref($$Options{$key}) eq 'CODE' and usage("$key undefined"); # where can 'CODE' come from?!
+}
+
 for $key (qw(vault Image client tree))
 {
 	length($$Options{$key}) or usage("$key undefined");
@@ -451,6 +458,18 @@ scalar @{$$Options{exclude}}
 
 if (!$$Options{'no-run'})
 {
+	$lock_file = "$vault/dirvish/lock_file";
+	if (! -f $lock_file)
+	{
+		open(LOCK, "+>", $lock_file) or seppuku 150, "cannot create $lock_file";
+		printf LOCK $$;
+		close(LOCK);
+	}
+	else
+	{
+		seppuku 151, "$lock_file already exists";
+	}
+
 	mkdir "$vault/$image", 0700
 		or seppuku 230, "mkdir $vault/$image failed";
 	mkdir $destree, 0755;
@@ -512,8 +531,9 @@ for $key (@summary_fields, 'RESET', sort
 $$Options{init} or push @rsyncargs, "--link-dest=$reftree";
 
 $rclient = undef;
-$$Options{client} ne $$Options{Server}
-	and $rclient = $$Options{client} . ':';
+if ($$Options{client} ne $$Options{Server} and $$Options{client} ne 'localhost') {
+	$rclient = $$Options{client} . ':';
+}
 
 $ENV{RSYNC_RSH} = $$Options{rsh};
 
@@ -586,7 +606,7 @@ if ($$Options{'pre-client'})
 		log	=> $log_file,
 		dir	=> $srctree,
 		env	=> $WRAPPER_ENV,
-		shell	=> (($$Options{client} eq $$Options{Server})
+		shell	=> (($$Options{client} eq $$Options{Server} or $$Options{client} eq 'localhost')
 			?  undef
 			: "$$Options{rsh} $$Options{client}"),
 	);
@@ -721,7 +741,7 @@ if ($$Options{'post-client'})
 		log	=> $log_file,
 		dir	=> $srctree,
 		env	=> $WRAPPER_ENV,
-		shell	=> (($$Options{client} eq $$Options{Server})
+		shell	=> (($$Options{client} eq $$Options{Server} or $$Options{client} eq 'localhost')
 			?  undef
 			: "$$Options{rsh} $$Options{client}"),
 	);
@@ -755,6 +775,8 @@ if ($$Options{'post-server'})
 	}
 }
 
+unlink($lock_file);
+
 if($status{fatal})
 {
 	system ("rm -rf $destree");
