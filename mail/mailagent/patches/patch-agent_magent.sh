$NetBSD: patch-agent_magent.sh,v 1.1 2011/12/14 03:03:47 sbd Exp $

--- agent/magent.sh.orig	2001-03-17 18:31:21.000000000 +0000
+++ agent/magent.sh
@@ -17,7 +17,7 @@ esac
 echo "Extracting agent/magent (with variable substitutions)"
 $spitshell >magent <<!GROK!THIS!
 $startperl
-	eval 'exec perl -S \$0 "\$@"'
+	eval 'exec $perlpath -S \$0 "\$@"'
 		if \$running_under_some_shell;
 
 # You'll need to set up a .forward file that feeds your mail to this script,
