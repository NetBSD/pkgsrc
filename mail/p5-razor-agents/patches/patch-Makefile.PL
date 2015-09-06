$NetBSD: patch-Makefile.PL,v 1.1 2015/09/06 17:13:56 wiz Exp $

https://github.com/Perl-Toolchain-Gang/ExtUtils-MakeMaker/issues/233

index d6169fd..71aa604 100644
--- Makefile.PL
+++ Makefile.PL
@@ -140,9 +140,9 @@ sub MY::install {
   my $inherited = $self->SUPER::install(@_);
 
   my $man5 = q{ \\
-		$(INST_MAN5DIR) $(INSTALLMAN5DIR)};
+		"$(INST_MAN5DIR)" "$(INSTALLMAN5DIR)"};
 
-  $inherited =~ s/(\$\((?:DEST)?INSTALL\w*MAN1DIR\))/$1$man5/gm;
+  $inherited =~ s/(\$\((?:DEST)?INSTALL\w*MAN1DIR\)")/$1$man5/gm;
 
   return $inherited;
 }
