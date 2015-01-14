$NetBSD: patch-config_perl.m4,v 1.1 2015/01/14 21:01:18 adam Exp $

--- config/perl.m4.orig	2013-09-02 20:53:17.000000000 +0000
+++ config/perl.m4
@@ -62,9 +62,7 @@ if test "$PORTNAME" = "win32" ; then
 perl_lib=`basename $perl_archlibexp/CORE/perl[[5-9]]*.lib .lib`
 test -e "$perl_archlibexp/CORE/$perl_lib.lib" && perl_embed_ldflags="-L$perl_archlibexp/CORE -l$perl_lib"
 else
-pgac_tmp1=`$PERL -MExtUtils::Embed -e ldopts`
-pgac_tmp2=`$PERL -MConfig -e 'print $Config{ccdlflags}'`
-perl_embed_ldflags=`echo X"$pgac_tmp1" | sed -e "s/^X//" -e "s%$pgac_tmp2%%" -e ["s/ -arch [-a-zA-Z0-9_]*//g"]`
+perl_embed_ldflags=`$PERL -MExtUtils::Embed -e ldopts`
 fi
 AC_SUBST(perl_embed_ldflags)dnl
 if test -z "$perl_embed_ldflags" ; then
