$NetBSD: patch-Blowfish.xs,v 1.1 2013/06/01 11:49:07 obache Exp $

* SvUPGRADE usage change for perl>=5.18
  https://rt.cpan.org/Public/Bug/Display.html?id=83924

--- Blowfish.xs.orig	2000-11-30 06:25:21.000000000 +0000
+++ Blowfish.xs
@@ -63,8 +63,7 @@ blowfish_crypt(input, output, ks, dir)
 			output = sv_newmortal();
 		output_len = 8;
 
-		if (!SvUPGRADE(output, SVt_PV))
-			croak("cannot use output argument as lvalue");
+		(void) SvUPGRADE(output, SVt_PV);
 
 		/* blowfish_crypt_8bytes(input, SvGROW(output, 8), ks, dir); */
 		/* HP-UX (HP cc) fix below, thanks Addi! */
