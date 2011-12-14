$NetBSD: patch-agent_maildist.SH,v 1.1 2011/12/14 03:03:47 sbd Exp $

--- agent/maildist.SH.orig	2001-03-17 18:31:22.000000000 +0000
+++ agent/maildist.SH
@@ -18,5 +18,5 @@ echo "Extracting agent/maildist (with va
 $spitshell >maildist <<!GROK!THIS!
 $startperl
-	eval "exec perl -S \$0 \$*"
+	eval "exec $perlpath -S \$0 \$*"
 		if \$running_under_some_shell;
 
