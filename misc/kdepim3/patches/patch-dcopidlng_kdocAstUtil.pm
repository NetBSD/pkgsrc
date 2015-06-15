$NetBSD: patch-dcopidlng_kdocAstUtil.pm,v 1.1 2015/06/15 09:24:31 joerg Exp $

--- dcopidlng/kdocAstUtil.pm.orig	2015-06-14 19:23:52.000000000 +0000
+++ dcopidlng/kdocAstUtil.pm
@@ -647,8 +647,7 @@ sub dumpAst
 		dumpAst( $kid );
 	}
 
-	print "\t" x $depth, "Documentation nodes:\n" if defined 
-		@{ $node->{Doc}->{ "Text" }};
+	print "\t" x $depth, "Documentation nodes:\n" if (@{ $node->{Doc}->{ "Text" }});
 
 	foreach $kid ( @{ $node->{Doc}->{ "Text" }} ) {
 		dumpAst( $kid );
