$NetBSD: patch-agent_package.SH,v 1.1 2011/12/14 03:03:47 sbd Exp $

--- agent/package.SH.orig	2001-03-17 18:31:23.000000000 +0000
+++ agent/package.SH
@@ -18,5 +18,5 @@ echo "Extracting agent/package (with var
 $spitshell >package <<!GROK!THIS!
 $startperl
-	eval "exec perl -S \$0 \$*"
+	eval "exec $perlpath -S \$0 \$*"
 		if \$running_under_some_shell;
 
