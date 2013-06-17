$NetBSD: patch-IDEA.xs,v 1.1 2013/06/17 11:25:27 wiz Exp $

Fix build with perl-5.18, from
https://rt.cpan.org/Public/Bug/Display.html?id=82010

--- IDEA.xs.orig	2003-01-19 02:48:04.000000000 +0000
+++ IDEA.xs
@@ -71,8 +71,7 @@ idea_crypt(input, output, ks)
 			output = sv_newmortal();
 		output_len = 8;
 
-		if (!SvUPGRADE(output, SVt_PV))
-			croak("cannot use output argument as lvalue");
+		SvUPGRADE(output, SVt_PV);
 
 		idea_crypt((u_int16_t *)input, (u_int16_t *)SvGROW(output, output_len), (u_int16_t *)ks);
 
