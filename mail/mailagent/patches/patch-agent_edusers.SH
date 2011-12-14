$NetBSD: patch-agent_edusers.SH,v 1.1 2011/12/14 03:03:47 sbd Exp $

--- agent/edusers.SH.orig	2001-03-17 18:31:17.000000000 +0000
+++ agent/edusers.SH
@@ -18,5 +18,5 @@ echo "Extracting agent/edusers (with var
 $spitshell >edusers <<!GROK!THIS!
 $startperl
-	eval "exec perl -S \$0 \$*"
+	eval "exec $perlpath -S \$0 \$*"
 		if \$running_under_some_shell;
 
