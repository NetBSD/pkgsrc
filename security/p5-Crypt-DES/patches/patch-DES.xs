$NetBSD: patch-DES.xs,v 1.1 2013/06/01 04:47:03 obache Exp $

* fixes for perl>=5.17.8
  https://rt.cpan.org/Public/Bug/Display.html?id=82943

--- DES.xs.orig	2005-12-08 15:52:50.000000000 +0000
+++ DES.xs
@@ -64,8 +64,7 @@ _des_crypt(input, output, ks, enc_flag)
 			output = sv_newmortal();
 		output_len = 8;
 
-		if (!SvUPGRADE(output, SVt_PV))
-			croak("cannot use output argument as lvalue");
+		(void) SvUPGRADE(output, SVt_PV);
 
 		perl_des_crypt(input, SvGROW(output, output_len), (i32 *)ks, enc_flag);
 
